/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/02 19:05:48 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "strutils.h"
#include "pipex.h"
#include "paths.h"

char	**extract_paths(t_cmd **cmds, int size, char *envp[])
{
	int		i;
	char	*env_path;
	char	**paths;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		env_path = ft_strdup("");
	else
		env_path = ft_strdup(envp[i] + 5);
	if (!env_path)
		error_exit(cmds, size);
	paths = ft_split(env_path, ':');
	free(env_path);
	if (!paths)
		error_exit(cmds, size);
	return (paths);
}

void	error_paths_exit(t_cmd **cmds, int size, char **paths)
{
	ft_free_strs(paths);
	error_exit(cmds, size);
}
