/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/02 19:41:50 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include "ft_string.h"
#include "strutils.h"
#include "commands.h"
#include "paths.h"

static char *find_executable(char *bin, char **paths);
static char	*find_path(char *bin, char**paths);
static void	skip_clean_cmd(t_cmd *cmd, int *fd_in_next_cmd, bool should_free);

void	get_cmds(t_cmd **cmds, int size, char *argv[], char *envp[])
{
	int		i;
	char	**paths;

	i = 0;
	paths = extract_paths(cmds, size, envp);
	if (cmds[0]->fds[IN] == -1)
		skip_clean_cmd(cmds[i++], &cmds[1]->fds[IN], false);
	while (i < size)
	{
		cmds[i]->argv = ft_split(argv[i + 2], ' ');
		if (!cmds[i]->argv)
			error_paths_exit(cmds, size, paths);
		cmds[i]->path = find_executable(cmds[i]->argv[0], paths);
		if (!cmds[i]->path)
			error_paths_exit(cmds, size, paths);
		i++;
	}
	ft_free_strs(paths);
}

static char *find_executable(char *bin, char **paths)
{
	char	*path;

	if (!bin)
		path = ft_strdup("");
	else if (!ft_strncmp(bin, "./", 2) || !ft_strncmp(bin, "../", 3) ||
		!ft_strncmp(bin, "/", 1))
		path = ft_strdup(bin);
	else if (!*paths)
		path = ft_strdup("");
	else
		path = find_path(bin, paths);
	return (path);
}

static char	*find_path(char *bin, char**paths)//TODO: TESTER en executant des fichiers non executable
{
	int		i;
	char	*path;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], bin);
		if (!path)
			return (NULL);
		if (!access(path, F_OK))
			return (path);
		free(path);
		path = NULL;
		i++;
	}
	path = ft_strdup("");
	return (path);
}

static void	skip_clean_cmd(t_cmd *cmd, int *fd_in_next_cmd, bool should_free)
{
	if (should_free)
		free(cmd->path);
	cmd->path = NULL;
	if (should_free)
		ft_free_strs(cmd->argv);
	cmd->argv = NULL;
	close(cmd->fds[OUT]);
	cmd->fds[OUT] = -1;
	close(*fd_in_next_cmd);
	*fd_in_next_cmd = -1;
}
