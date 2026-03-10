/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/07 15:19:51 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fds.h"
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include "ft_stdio.h"
#include "pipex.h"
#include "create_children.h"

void	get_fds_io(t_cmd **cmds, int size, t_io_data *io)
{
	cmds[0]->fds[IN] = io->fd_infile;
	cmds[size - 1]->fds[OUT] = open(io->outfile_path, io->outfile_flags, 0644);
	if (cmds[size - 1]->fds[OUT] == -1)
	{
		ft_dprintf(2, "pipex: %s: %s\n", io->outfile_path, strerror(errno));
		io->skip_outfile = true;
	}
}

void	get_fds(t_cmd **cmds, int size, int i, t_io_data *io)
{
	int	fds[2];
	int	wstatus;

	if (pipe(fds) == -1)
	{
		wait_children(cmds, size, io, &wstatus);
		error_exit(cmds, size);
	}
	cmds[i]->fds[OUT] = fds[OUT];
	cmds[i + 1]->fds[IN] = fds[IN];
}

void	duplicate_fds(t_cmd *cmd)
{
	if (cmd->fds[IN] != -1)
		dup2(cmd->fds[IN], STDIN_FILENO);
	if (cmd->fds[OUT] != -1)
		dup2(cmd->fds[OUT], STDOUT_FILENO);
}

void	close_fds(int (*fds)[2])
{
	if ((*fds)[IN] != -1)
		close((*fds)[IN]);
	(*fds)[IN] = -1;
	if ((*fds)[OUT] != -1)
		close((*fds)[OUT]);
	(*fds)[OUT] = -1;
}

void	close_all(t_cmd **cmds, int size)
{
	while (size)
	{
		size--;
		close_fds(&cmds[size]->fds);
	}
}
