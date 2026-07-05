/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <private_mail>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 14:47:57 by cboucher          #+#    #+#             */
/*   Updated: 2026/07/05 20:47:57 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	isdead_and_manage_usleep(t_ctx *ctx, t_philo *philo);

bool	is_dead(t_ctx *ctx, t_philo *philo)
{
	uint64_t	hunger_death;

	hunger_death = get_timestamp_in_ms(&philo->hunger_death, 0);
	if (gettimeofday_in_ms(0) > hunger_death)
	{
		hunger_death -= ctx->started_timestamp;
		philo->state = DIED;
		pthread_mutex_lock(&ctx->m_start_end);
		ctx->start_end = true;
		pthread_mutex_unlock(&ctx->m_start_end);
		pthread_mutex_lock(&ctx->m_stdout);
		printf("%zu %d died\n", hunger_death, philo->id + 1);//TODO:attention au 10ms de decallage ?
		pthread_mutex_unlock(&ctx->m_stdout);
		return (true);
	}
	return (false);
}

bool	thinking(t_ctx *ctx, t_philo *philo)
{
	uint64_t	time;

	if (is_dead(ctx, philo))
		return (false);
	time = gettimeofday_in_ms(ctx->started_timestamp);
	philo->state = WAIT_FORK_1;
	pthread_mutex_lock(&ctx->m_stdout);
	printf("%zu %d is thinking\n", time, philo->id + 1);
	pthread_mutex_unlock(&ctx->m_stdout);
	return (true);
}

bool	eating(t_ctx *ctx, t_philo *philo)
{
	uint64_t	time;

	if (is_dead(ctx, philo))
		return (false);
	gettimeofday(&philo->hunger_death, NULL);
	add_milliseconds(&philo->hunger_death, ctx->time_to_die);
	philo->total_meals++;
	time = gettimeofday_in_ms(ctx->started_timestamp);
	philo->state = SLEEPING;
	pthread_mutex_lock(&ctx->m_stdout);
	printf("%zu %d is eating\n", time, philo->id + 1);
	pthread_mutex_unlock(&ctx->m_stdout);
	usleep(ctx->time_to_eat * 1000);//TODO:alternative calculer decallage avec gettimeofday? fair ?
	put_forks_on_the_table(ctx, philo);
	return (true);
}

bool	sleeping(t_ctx *ctx, t_philo *philo)
{
	uint64_t	time;

	if (is_dead(ctx, philo))
		return (false);
	time = gettimeofday_in_ms(ctx->started_timestamp);
	if (time + ctx->time_to_sleep
		> get_timestamp_in_ms(&philo->hunger_death, ctx->started_timestamp))
		philo->state = DIED;
	else
		philo->state = THINKING;
	pthread_mutex_lock(&ctx->m_stdout);
	printf("%zu %d is sleeping\n", time, philo->id + 1);
	pthread_mutex_unlock(&ctx->m_stdout);
	if (isdead_and_manage_usleep(ctx, philo))
		return (false);
	return (true);
}

static bool	isdead_and_manage_usleep(t_ctx *ctx, t_philo *philo)
{
	uint64_t	time;

	if (philo->state == DIED)
	{
		time = get_timestamp_in_ms(&philo->hunger_death, ctx->started_timestamp);
		while (gettimeofday_in_ms(ctx->started_timestamp) < time)
			;//TODO: metre un petit usleep ?
		pthread_mutex_lock(&ctx->m_stdout);
		printf("%zu %d died\n", time, philo->id + 1);//TODO:attention au 10ms de decallage ?
		pthread_mutex_unlock(&ctx->m_stdout);
		return (true);
	}
	else
		usleep(ctx->time_to_sleep * 1000);
	return (false);
}
