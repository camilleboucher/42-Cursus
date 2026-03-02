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

#include "ft_string.h"
#include "strutils.h"
#include "commands.h"
#include "paths.h"

static char *find_executable(t_cmd *cmd, char **paths);
static char	*find_path(char *bin, char**paths);

void	get_cmds(t_cmd **cmds, int size, char *argv[], char *envp[])
{
	int		i;
	char	**paths;

	i = 0;
	paths = extract_paths(cmds, size, envp);
	if (cmds[0]->fds[IN] == -1)
	{
		cmds[0]->path = NULL;
		cmds[0]->argv = NULL;
		close(cmds[0]->fds[OUT]);
		close(cmds[1]->fds[IN]);
		i++;
	}
	while (i < size)
	{
		cmds[i]->argv = ft_split(argv[i + 2], ' ');
		if (!cmds[i]->argv)
			error_paths_exit(cmds, size, paths);
		cmds[i]->path = find_executable(cmds[i], paths);
		//TODO:protection path
	}
	free_paths(paths);
}

static char *find_executable(t_cmd *cmd, char **paths)
{
	char	*path;

	if (!ft_strncmp(cmd->argv[0], "./", 2))
		path = ft_strdup(cmd->argv[0]);
	else
	{
		path = find_path(cmd->argv[0], paths);
	}
	return (path);
}

static char	*find_path(char *bin, char**paths)
{
	//TODO: a continuer : strjoin old new et utiliser fonction access dans boucle etc...
}
