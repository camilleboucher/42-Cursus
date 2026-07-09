/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <private_mail>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:48:43 by cboucher          #+#    #+#             */
/*   Updated: 2026/07/09 18:50:21 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_stdout_and_startend(t_ctx *ctx)
{
	pthread_mutex_lock(&ctx->m_stdout);
	pthread_mutex_lock(&ctx->m_start_end);
}

void	unlock_stdout_and_startend(t_ctx *ctx)
{
	pthread_mutex_unlock(&ctx->m_stdout);
	pthread_mutex_unlock(&ctx->m_start_end);
}
