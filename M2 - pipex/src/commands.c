/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/02 16:42:19 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"
#include "ft_string.h"
#include "strutils.h"

static char	**extract_paths(char *envp[]);

void	get_cmds(t_cmd **cmds, int size, char *argv[], char *envp[])
{
	int		i;
	char	**paths;

	i = 0;
	paths = extract_paths(envp);
	if (cmds[0]->fds[IN] == -1)
	{
		close(cmds[0]->fds[OUT]);
		close(cmds[1]->fds[IN]);
		i++;
	}
	while (i < size)
	{
		//extract path
		//extract argv
	}
}

static char	**extract_paths(char *envp[])
{
	int		i;
	char	*env_path;
	char	**paths;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	env_path = ft_strdup(envp[i] + 5); //TODO:proteger
	paths = ft_split(env_path, ':');//TODO:proteger et enlever le \n de la derniere avec substr
	return (paths);
}
/*
	char	***cmds;

	cmds = malloc(sizeof(char **) * 2);
	cmds[0] = ft_split(argv[2], ' ');
	cmds[1] = ft_split(argv[3], ' ');
	if (!cmds[0] || !cmds[1])
		free_cmds_and_exit(cmds);
	pipex->cmds = cmds;
}

void	free_cmds(char ***cmds)
{
	uint8_t		i;
	uint16_t	j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (cmds[i][j])
		{
			free(cmds[i][j]);
			j++;
		}
		free(cmds[i]);
		i++;
	}
	free(cmds);
}

void	free_cmds_and_exit(char ***cmds)
{
	perror("pipex");
	free_cmds(cmds);
	exit(EXIT_FAILURE);
}*/
