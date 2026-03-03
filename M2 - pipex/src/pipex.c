/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/02 15:33:22 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "pipex.h"
#include "fds.h"
#include "strutils.h"

static t_cmd	**init_pipex(int size);
static void		clean_pipex(t_cmd **cmds, int size);

int main(int argc, char *argv[], char *envp[])
{
	t_cmd	**cmds;
	int		size;

	if (argc != 5)
	{
		ft_dprintf(2, "pipex: the pipex program takes 4 arguments\n");
		return (EXIT_FAILURE);
	}
	size = argc - 3;
	cmds = init_pipex(size);
	get_fds(cmds, size, argv[1], argv[argc - 1]);
	get_cmds(cmds, size, argv, envp);
	clean_pipex(cmds, size);
	return (EXIT_SUCCESS);
}

static t_cmd	**init_pipex(int size)
{
	t_cmd	**cmds;
	int		i;

	i = size;
	cmds = ft_calloc(sizeof(t_cmd *), size);
	if (!cmds)
		error_exit(cmds, size);
	while (i)
	{
		i--;
		cmds[i] = malloc(sizeof(t_cmd));
		if (!cmds[i])
			error_exit(cmds, size);
	}
	return (cmds);
}

static void	clean_pipex(t_cmd **cmds, int size)
{
	int	i;

	if (cmds)
	{
		i = size;
		while (i)
		{
			i--;
			free(cmds[i]->path);
			ft_free_strs(cmds[i]->argv);
			if (cmds[i]->fds[IN] != -1)
				close(cmds[i]->fds[IN]);
			if (cmds[i]->fds[OUT] != -1)
				close(cmds[i]->fds[OUT]);
			free(cmds[i]);
		}
		free(cmds);
	}
}

void	error_exit(t_cmd **cmds, int size)
{
	perror("pipex");
	clean_pipex(cmds, size);
	exit(EXIT_FAILURE);
}
