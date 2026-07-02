/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <private_mail>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 16:39:18 by cboucher          #+#    #+#             */
/*   Updated: 2026/07/02 20:01:34 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	start_philo(int agrc, char **argv);
static bool	init_ctx(t_ctx *ctx, int argc, char **argv);
static bool	init_philos(t_ctx *ctx, t_philo **philos, int n, int time_to_die);
static void	destroy_philos(t_philo *philos, int n);

int	main(int argc, char **argv)
{
	if (!check_args(argc, argv))
		return (EXIT_BAD_ARGS);
	if (!start_philo(argc, argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static bool	start_philo(int argc, char **argv)
{
	t_ctx	ctx;
	t_philo	*philos;
	int		nb_philos;

	if (!init_ctx(&ctx, argc, argv))
		return (false);
	philos = ctx.philos;
	nb_philos = ctx.nb_philos;
	if (!init_philos(&ctx, &philos, nb_philos, ctx.time_to_die))
		return (false);
	if (!create_philos_threads(philos, nb_philos))
	{
		destroy_philos(philos, nb_philos);
		return (false);
	}
	destroy_philos(philos, nb_philos);
	return (true);
}

static bool	init_ctx(t_ctx *ctx, int argc, char **argv)
{
	ctx->nb_philos = atoi(argv[1]);
	ctx->time_to_die = atoi(argv[2]);
	ctx->time_to_eat = atoi(argv[3]);
	ctx->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		ctx->nb_times_must_eat = atoi(argv[5]);
	else
		ctx->nb_times_must_eat = -1;
	if (!check_limit_val(ctx, argc))
	{
		printf("%s", USAGE_MAX_LIMIT_MSG);
		return (false);
	}
	return (true);
}

static bool	init_philos(t_ctx *ctx, t_philo **philos, int n, int time_to_die)
{
	t_philo	*philo;

	*philos = malloc(sizeof(t_philo) * n);
	if (!*philos)
		return (false);
	while (n)
	{
		n--;
		philo = *philos + n;
		philo->id = n;
		if (gettimeofday(&philo->hunger_death, NULL) == -1)
			return (false);
		add_milliseconds(&philo->hunger_death, time_to_die);
		philo->total_meals = 0;
		pthread_mutex_init(&philo->m_fork, NULL);
		philo->fork = false;
		philo->ctx = ctx;
	}
	return (true);
}

static void	destroy_philos(t_philo *philos, int n)
{
	while (n)
	{
		n--;
		pthread_mutex_destroy(&philos[n].m_fork);
	}
	free(philos);
}
