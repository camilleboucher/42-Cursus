/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <private_mail>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:50:39 by cboucher          #+#    #+#             */
/*   Updated: 2026/07/05 20:47:04 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	try_taking_fork(pthread_mutex_t *m_fork, bool *fork);
static void	print_fork_message(t_ctx *ctx, t_philo *philo);

void	try_taking_first_fork(t_ctx *ctx, int current, t_philo *philo)
{
	int	i;

	if (philo->id % 2 == 0)
	{
		if (try_taking_fork(&philo->m_fork, &philo->fork))
			print_fork_message(ctx, philo);
	}
	else
	{
		i = current + 1;
		if (i == ctx->nb_philos)
			i = 0;
		if (try_taking_fork(&ctx->philos[i].m_fork, &ctx->philos[i].fork))
			print_fork_message(ctx, philo);
	}
}

void	try_taking_second_fork(t_ctx *ctx, int current, t_philo *philo)
{
	int	i;

	if (philo->id % 2 == 0)
	{
		i = current + 1;
		if (i == ctx->nb_philos)
			i = 0;
		if (try_taking_fork(&ctx->philos[i].m_fork, &ctx->philos[i].fork))
			print_fork_message(ctx, philo);
	}
	else
	{
		if (try_taking_fork(&philo->m_fork, &philo->fork))
			print_fork_message(ctx, philo);
	}
}

void	put_forks_on_the_table(t_ctx *ctx, t_philo *philo)
{
	int	i;

	i = philo->id + 1;
	if (i == ctx->nb_philos)
		i = 0;
	pthread_mutex_lock(&philo->m_fork);
	philo->fork = false;
	pthread_mutex_unlock(&philo->m_fork);
	pthread_mutex_lock(&ctx->philos[i].m_fork);
	ctx->philos[i].fork = false;
	pthread_mutex_unlock(&ctx->philos[i].m_fork);
}

static bool	try_taking_fork(pthread_mutex_t *m_fork, bool *fork)
{
	bool	took;

	took = false;
	pthread_mutex_lock(m_fork);
	if (!*fork)
	{
		*fork = true;
		took = true;
	}
	pthread_mutex_unlock(m_fork);
	return (took);
}

static void	print_fork_message(t_ctx *ctx, t_philo *philo)
{
	uint64_t	time;

	time = gettimeofday_in_ms(ctx->started_timestamp);
	philo->state++;
	pthread_mutex_lock(&ctx->m_stdout);
	printf("%zu %d has taken a fork\n", time, philo->id + 1);
	pthread_mutex_unlock(&ctx->m_stdout);
}
