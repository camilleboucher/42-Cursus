/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:49:58 by Camille           #+#    #+#             */
/*   Updated: 2026/05/08 17:19:54 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_io(char *path, int flags, bool to_read, bool *io_is_invalid);

bool	set_redirections(t_minishell *sh, t_cmd *cmd, t_io *io)
{
	while (io)
	{
		if (io->infile)
		{
			close_fd(&cmd->fds[0]);
			if (io->is_lim)
				cmd->fds[0] = get_fd_heredoc(sh, io);
			else
				cmd->fds[0] = open_io(io->infile, O_RDONLY, true, &io->invalid);
			if (cmd->fds[0] == -1)
				return (false);
		}
		if (io->outfile)
		{
			close_fd(&cmd->fds[1]);
			cmd->fds[1] = open_io(io->outfile, io->outfile_flags,
					false, &io->invalid);
			if (cmd->fds[1] == -1)
				return (false);
		}
		io = io->next;
	}
	return (true);
}

static int	open_io(char *path, int flags, bool to_read, bool *io_is_invalid)
{
	int	fd;

	if (to_read)
		fd = open(path, flags);
	else
		fd = open(path, flags, 0644);
	if (fd == -1)
	{
		ft_dprintf(2, "minishell: %s: %s\n", path, strerror(errno));
		*io_is_invalid = true;
	}
	return (fd);
}
