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

void	get_fds(t_cmd **cmds, int size, t_io_data *io)
{
	int	fds[2];
	int	fds_errmsg[2];
	int	nb_pipes;

	cmds[0]->fds[IN] = io->fd_infile;
	cmds[size - 1]->fds[OUT] = open(io->outfile_path, io->outfile_flags, 0644);
	if (cmds[size - 1]->fds[OUT] == -1)
		ft_dprintf(2, "pipex: %s: %s\n", io->outfile_path, strerror(errno));
	nb_pipes = 1;
	while (nb_pipes < size)
	{
		if (pipe(fds) == -1)
			error_exit(cmds, size);
		cmds[nb_pipes - 1]->fds[OUT] = fds[OUT];
		cmds[nb_pipes]->fds[IN] = fds[IN];
		if (pipe(fds_errmsg) == - 1)
			error_exit(cmds, size);
		cmds[nb_pipes]->fds_errmsg[OUT] = fds_errmsg[OUT];
		cmds[nb_pipes]->fds_errmsg[IN] = fds_errmsg[IN];
		nb_pipes++;
	}
}

void	duplicate_fds(t_cmd *cmd)
{
	if (cmd->fds[IN] != -1)
		dup2(cmd->fds[IN], STDIN_FILENO);
	if (cmd->fds[OUT] != -1)
		dup2(cmd->fds[OUT], STDOUT_FILENO);
	if (cmd->fds_errmsg[OUT] != -1)
		dup2(cmd->fds_errmsg[OUT], STDERR_FILENO);
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
		close_fds(&cmds[size]->fds_errmsg);
	}
}
