/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/11 23:07:56 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "strutils.h"
#include "pipex.h"
#include "fds.h"
#include "create_children.h"

static t_cmd	**init_pipex(int size, t_io_data *io);
static int		get_fd_infile(char *infile_path, t_io_data *io);

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd		**cmds;
	int			size;
	t_io_data	io;
	int			exit_code;

	if (argc != 5)
	{
		ft_dprintf(2, "pipex: the pipex program takes 4 arguments\n");
		return (EXIT_FAILURE);
	}
	size = argc - 3;
	cmds = init_pipex(size, &io);
	io.fd_infile = get_fd_infile(argv[1], &io);
	io.outfile_path = argv[argc - 1];
	io.outfile_flags = O_CREAT | O_TRUNC | O_WRONLY;
	get_fds_io(cmds, size, &io);
	get_cmds(cmds, size, argv, envp);
	exit_code = make_love(cmds, size, envp, &io);
	clean_pipex(cmds, size);
	return (exit_code);
}

static t_cmd	**init_pipex(int size, t_io_data *io)
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
		cmds[i] = ft_calloc(sizeof(t_cmd), 1);
		if (!cmds[i])
			error_exit(cmds, size);
		cmds[i]->pid = -1;
	}
	io->skip_infile = false;
	io->skip_outfile = false;
	return (cmds);
}

void	clean_pipex(t_cmd **cmds, int size)
{
	int	i;

	if (cmds)
	{
		i = size;
		while (i)
		{
			i--;
			if (cmds[i])
			{
				free(cmds[i]->path);
				ft_free_strs(cmds[i]->argv);
				close_fds(&cmds[i]->fds);
				free(cmds[i]);
			}
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

static int	get_fd_infile(char *infile_path, t_io_data *io)
{
	int	fd_infile;

	fd_infile = open(infile_path, O_RDONLY);
	if (fd_infile == -1)
	{
		ft_dprintf(2, "pipex: %s: %s\n", infile_path, strerror(errno));
		io->skip_infile = true;
	}
	return (fd_infile);
}
