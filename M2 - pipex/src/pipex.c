/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/02/26 21:19:06 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stdio.h"
#include "pipex.h"
#include "commands.h"

static void	get_fds(t_pipex *pipex, char *infile);

int main(int argc, char *argv[], char *env[])
{
	t_pipex	pipex;

	if (argc != 5)
	{
		ft_printf("pipex: the pipex program takes 4 arguments\n");
		return (EXIT_FAILURE);
	}
	get_cmds(argv, &pipex);
	get_fds(&pipex, argv[1]);
	(void)env;
	free_cmds(pipex.cmds);
	return (EXIT_SUCCESS);
}

#include <fcntl.h>
static void	get_fds(t_pipex *pipex, char *infile)
{
	pipex->fds[0] = open(infile, O_RDONLY);
	if (pipex->fds[0] == -1)
		free_cmds_and_exit(pipex->cmds);
	if (pipe(&pipex->fds[1]) == -1)
	{
		close(pipex->fds[0]);
		free_cmds_and_exit(pipex->cmds);
	}
}
