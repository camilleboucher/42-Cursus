/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_children_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/11 12:16:32 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include "create_children_utils.h"
#include "fds.h"

bool	skip_iofiles(int size, int *i, t_io_data *io)
{
	if (*i == size - 1)
	{
		if (io->skip_outfile)
		{
			(*i)++;
			return (true);
		}
		else
			return (false);
	}
	else if (*i == 0 && io->skip_infile)
	{
		(*i)++;
		return (true);
	}
	return (false);
}

void	close_pipe(t_cmd **cmds, int size, int i)
{
	if (i && cmds[i - 1]->fds[OUT] != -1)
	{
		close(cmds[i - 1]->fds[OUT]);
		cmds[i - 1]->fds[OUT] = -1;
	}
	if (cmds[i]->fds[IN] != -1)
		close(cmds[i]->fds[IN]);
	cmds[i]->fds[IN] = -1;
	if (i == size -1)
		close_fds(&cmds[i]->fds);
}

int	get_exit_code(int wstatus)
{
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	else if (WIFSIGNALED(wstatus))
		return (WTERMSIG(wstatus) + 128);
	return (EXIT_FAILURE);
}
