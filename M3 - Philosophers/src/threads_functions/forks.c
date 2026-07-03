/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <private_mail>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 13:50:39 by cboucher          #+#    #+#             */
/*   Updated: 2026/07/03 15:36:15 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	print_fork_message(int	philo);

void	try_taking_first_fork(t_philo **philos, int current, t_philo *philo)
{
	int	i;

	if (philo->id % 2 == 0)
	{
		if (try_taking_fork(&philo->m_fork, &philo->fork))
			print_fork_message(philo->id);
	}
	else
	{
		i = current + 1;
		if (i == philo->ctx->nb_philos)
			i = 0;
		if (try_taking_fork(&philos[i]->m_fork, &philos[i]->fork))
			print_fork_message(philos[i]->id);
	}
}

void	try_taking_second_fork(t_philo **philos, int current, t_philo *philo)
{
	int	i;

	if (philo->id % 2 == 0)
	{
		i = current + 1;
		if (i == philo->ctx->nb_philos)
			i = 0;
		if (try_taking_fork(&philos[i]->m_fork, &philos[i]->fork))
			print_fork_message(philos[i]->id);
	}
	else
	{
		if (try_taking_fork(&philo->m_fork, &philo->fork))
			print_fork_message(philo->id);
	}
}

bool	try_taking_fork(pthread_mutex_t *m_fork, bool *fork)
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

static void	print_fork_message(int	philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("%zu %d has taken a fork", get_timestamp_in_ms(&tv), philo + 1);
}
