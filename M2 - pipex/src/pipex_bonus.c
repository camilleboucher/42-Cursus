/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/07 15:59:34 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include "strutils.h"
#include "pipex.h"
#include "fds.h"
#include "create_children.h"
#include "here_doc_bonus.h"

static t_cmd	**init_pipex(int size);
static void		get_io_files_data(int argc, char *argv[], t_io_data *io);

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd		**cmds;
	int			size;
	t_io_data	io;
	int			exit_code;

	if (argc < 5)
	{
		ft_dprintf(2,
			"pipex: the pipex (bonus) program takes at least 4 arguments\n");
		return (EXIT_FAILURE);
	}
	size = argc - 3;
	get_io_files_data(argc, argv, &io);
	if (io.outfile_flags == (O_CREAT | O_APPEND | O_WRONLY))
		size--;
	cmds = init_pipex(size);
	get_fds(cmds, size, &io);
	if (io.outfile_flags == (O_CREAT | O_APPEND | O_WRONLY))
		get_cmds(cmds, size, argv + 1, envp);
	else
		get_cmds(cmds, size, argv, envp);
	exit_code = make_love(cmds, size, envp, &io);
	clean_pipex(cmds, size);
	return (exit_code);
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
		cmds[i] = ft_calloc(sizeof(t_cmd), 1);
		if (!cmds[i])
			error_exit(cmds, size);
		cmds[i]->pid = -1;
	}
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

static void	get_io_files_data(int argc, char *argv[], t_io_data *io)
{
	io->skip_infile = false;
	io->skip_outfile = false;
	io->outfile_path = argv[argc - 1];
	if ((ft_strlen(argv[1]) == 8) && !ft_strncmp(argv[1], "here_doc", 8))
	{
		if (argc < 6)
		{
			ft_dprintf(2, "pipex: the pipex (bonus) program \
takes at least 5 arguments with the uses of a here document\n");
			exit(EXIT_FAILURE);
		}
		io->outfile_flags = O_CREAT | O_APPEND | O_WRONLY;
		io->fd_infile = get_fd_heredoc(argv[2], ft_strlen(argv[2]));
	}
	else
	{
		io->outfile_flags = O_CREAT | O_TRUNC | O_WRONLY;
		io->fd_infile = open(argv[1], O_RDONLY);
		if (io->fd_infile == -1)
		{
			ft_dprintf(2, "pipex: %s: %s\n", argv[1], strerror(errno));
			io->skip_infile = true;
		}
	}
}
