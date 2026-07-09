/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <private_mail>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:41:27 by cboucher          #+#    #+#             */
/*   Updated: 2026/07/09 18:49:45 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	waiting_rules(t_ctx *ctx, t_philo *philo, bool *first_loop)
{
	if (*first_loop && ctx->nb_philos_is_even && philo->is_even)
		usleep(30000);
	else if (!ctx->nb_philos_is_even)
	{
		if (ctx->time_to_eat >= ctx->time_to_sleep)
		{
			if (philo->is_even)
				usleep(ctx->time_to_eat * 1000);
			else if (!*first_loop)
				usleep(ctx->time_to_eat * 1000);
		}
		else if (*first_loop && philo->is_even)
			usleep(ctx->time_to_eat * 1000);
	}
	if (*first_loop)
		*first_loop = false;
}
