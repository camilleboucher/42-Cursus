/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/06 13:38:56 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include "ft_string.h"
#include "strutils.h"
#include "commands.h"
#include "paths.h"

static char	*find_executable(char *bin, char **paths);
static char	*find_path(char *bin, char**paths);
static void	skip_clean_cmd(t_cmd *cmd, int *pipe_fd_next);

void	get_cmds(t_cmd **cmds, int size, char *argv[], char *envp[])
{
	int		i;
	char	**paths;

	i = 0;
	paths = extract_paths(cmds, size, envp);
	if (cmds[0]->fds[IN] == -1)
		skip_clean_cmd(cmds[i++], &cmds[1]->fds[IN]);
	if (cmds[--size]->fds[OUT] == -1)
		skip_clean_cmd(cmds[size], &cmds[size]->fds[IN]);
	size++;
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

static char	*find_executable(char *bin, char **paths)
{
	char	*path;

	if (!bin)
		path = ft_strdup("");
	else if (ft_strchr(bin, '/'))
		path = ft_strdup(bin);
	else if (!*paths)
		path = ft_strdup("");
	else
		path = find_path(bin, paths);
	return (path);
}

static char	*find_path(char *bin, char**paths)
{
	int		i;
	char	*path;
	char	*prepath;

	i = 0;
	while (paths[i])
	{
		prepath = ft_strjoin(paths[i], "/");
		if (!prepath)
			return (NULL);
		path = ft_strjoin(prepath, bin);
		free(prepath);
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

static void	skip_clean_cmd(t_cmd *cmd, int *pipe_fd_next)
{
	if (cmd->fds[OUT] != -1)
		close(cmd->fds[OUT]);
	cmd->fds[OUT] = -1;
	if (*pipe_fd_next != -1)
		close(*pipe_fd_next);
	*pipe_fd_next = -1;
}
