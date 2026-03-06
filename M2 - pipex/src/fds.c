/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/06 13:49:08 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include "ft_stdio.h"
#include "pipex.h"

void	get_fds(t_cmd **cmds, int size, char *infile, char *outfile)
{
	int	fds[2];

	cmds[0]->fds[IN] = open(infile, O_RDONLY);
	if (cmds[0]->fds[IN] == -1)
		ft_dprintf(2, "pipex: %s: %s\n", infile, strerror(errno));
	cmds[1]->fds[OUT] = open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (cmds[1]->fds[OUT] == -1)
		ft_dprintf(2, "pipex: %s: %s\n", outfile, strerror(errno));
	if (pipe(fds) == -1)
		error_exit(cmds, size);
	cmds[0]->fds[OUT] = fds[1];
	cmds[1]->fds[IN] = fds[0];
}

void	close_fds(t_cmd *cmd)
{
	if (cmd->fds[IN] != -1)
		close(cmd->fds[IN]);
	cmd->fds[IN] = -1;
	if (cmd->fds[OUT] != -1)
		close(cmd->fds[OUT]);
	cmd->fds[OUT] = -1;
}

void	close_all_fds(t_cmd **cmds, int size)
{
	while (size)
	{
		size--;
		close_fds(cmds[size]);
	}
}
