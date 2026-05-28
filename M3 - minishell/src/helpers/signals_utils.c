/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:15:21 by Camille           #+#    #+#             */
/*   Updated: 2026/05/11 17:22:48 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ignore_signals_and_handle_sigint(t_minishell *sh)
{
	ignore_signals();
	if (g_signal == SIGINT)
		sh->exit_c = SIGINT + 128;
	g_signal = 0;
}
