/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 11:30:50 by Camille           #+#    #+#             */
/*   Updated: 2026/04/12 11:33:53 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fds(int (*fds)[2])
{
	close_fd(&(*fds)[0]);
	close_fd(&(*fds)[1]);
}

void	close_fd(int *fd)
{
	if (*fd != -1)
		close(*fd);
	*fd = -1;
}

void	duplicate_fds(t_cmd *cmd)
{
	if (cmd->fds[0] != -1)
		dup2(cmd->fds[0], STDIN_FILENO);
	if (cmd->fds[1] != -1)
		dup2(cmd->fds[1], STDOUT_FILENO);
}

void	close_all_fds(t_cmd **cmds, int nb_cmds)
{
	while (nb_cmds)
	{
		nb_cmds--;
		close_fds(&cmds[nb_cmds]->fds);
	}
}
