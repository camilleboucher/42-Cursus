/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 17:05:26 by Camille           #+#    #+#             */
/*   Updated: 2026/04/12 11:31:07 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_pipe(t_minishell *sh, int *curr_cmd_fd_out, int *next_cmd_fd_in)
{
	int	fds[2];

	if (pipe(fds) == -1)
		error_exit(sh, sh->nb_cmds);
	if (*curr_cmd_fd_out == -1)
		*curr_cmd_fd_out = fds[1];
	else
		close_fd(&fds[1]);
	*next_cmd_fd_in = fds[0];
}
