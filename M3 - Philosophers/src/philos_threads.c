/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <private_mail>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:48:18 by cboucher          #+#    #+#             */
/*   Updated: 2026/07/05 20:30:54 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*routine(void *arg);
static void	wait_for_synchro_start(t_ctx *ctx);
static bool	end_simulation(t_ctx *ctx, t_philo *philo);
static void	set_timestamps(t_ctx *ctx, t_philo *philos, int n);

bool	create_philos_threads(t_ctx *ctx, t_philo *philos, int n)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < n)
	{
		philo = philos + i;
		if (pthread_create(&philo->thread, NULL, &routine, philo))
			return (false);
		i++;
	}
	set_timestamps(ctx, philos, n);
	pthread_mutex_lock(&ctx->m_start_end);
	ctx->start_end = false;
	pthread_mutex_unlock(&ctx->m_start_end);
	i = 0;
	while (i < n)
	{
		philo = philos + i;
		if (pthread_join(philo->thread, NULL))
			return (false);
		i++;
	}
	return (true);
}

static void	*routine(void *arg)
{
	t_philo	*philo;
	t_ctx	*ctx;

	philo = (t_philo *) arg;
	ctx = philo->ctx;
	wait_for_synchro_start(ctx);
	while (1)
	{
		if (!end_simulation(ctx, philo)
			&& ((philo->state == THINKING && thinking(ctx, philo))
			|| (philo->state == WAIT_FORK_1
			&& try_taking_first_fork(ctx, philo->id, philo))
			|| (philo->state == WAIT_FORK_2
			&& try_taking_second_fork(ctx, philo->id, philo))
			|| (philo->state == EATING && eating(ctx, philo))
			|| (philo->state == SLEEPING && sleeping(ctx, philo))
			|| (philo->state == DIED)))
			break;
	}
	return (NULL);
}

static void	wait_for_synchro_start(t_ctx *ctx)
{
	while (1)
	{
		pthread_mutex_lock(&ctx->m_start_end);
		if (!ctx->start_end)
		{
			pthread_mutex_unlock(&ctx->m_start_end);
			break ;
		}
		pthread_mutex_unlock(&ctx->m_start_end);
	}
}

static bool	end_simulation(t_ctx *ctx, t_philo *philo)
{
	pthread_mutex_lock(&ctx->m_start_end);
	if (ctx->start_end || philo->total_meals == ctx->nb_times_must_eat)
	{
		pthread_mutex_unlock(&ctx->m_start_end);
		return (true);
	}
	pthread_mutex_unlock(&ctx->m_start_end);
	return (false);
}

static void	set_timestamps(t_ctx *ctx, t_philo *philos, int n)
{
	int	i;

	ctx->started_timestamp = gettimeofday_in_ms(0);
	i = 0;
	while (i < n)
	{
		gettimeofday(&philos[i].hunger_death, NULL);
		add_milliseconds(&philos[i].hunger_death, ctx->time_to_die);
		i++;
	}
}

