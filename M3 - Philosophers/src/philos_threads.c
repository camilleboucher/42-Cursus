/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <private_mail>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:48:18 by cboucher          #+#    #+#             */
/*   Updated: 2026/07/03 13:58:53 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

void	*routine(void *arg);

bool	create_philos_threads(t_philo *philos, int n)
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
	i = 0;
	while (i < n)
	{
		philo = philos + i;
		if (pthread_join(philo->thread, NULL))
			return (false);
		i++;
	}
	if (philo->ctx->sysfail)
		return (false);
	return (true);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (1)
	{
		if (philo->ctx->sysfail)
			break ;
	}
	return (NULL);
}
