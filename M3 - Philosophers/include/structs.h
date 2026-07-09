/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <private_mail>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 16:27:29 by cboucher          #+#    #+#             */
/*   Updated: 2026/07/07 14:06:12 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

enum e_state
{
	THINKING,
	WAIT_FORK_1,
	WAIT_FORK_2,
	EATING,
	SLEEPING,
	DIED
};

typedef struct s_philo
{
	int				id;
	int				n;
	bool			is_even;
	enum e_state	state;
	struct timeval	hunger_death;
	int				total_meals;
	pthread_t		thread;
	pthread_mutex_t	m_fork;
	bool			fork;
	struct s_ctx	*ctx;
}	t_philo;

typedef struct s_ctx
{
	int				nb_philos;
	bool			nb_philos_is_even;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_times_must_eat;
	uint64_t		start_timestamp;
	t_philo			*philos;
	pthread_mutex_t	m_stdout;
	pthread_mutex_t	m_start_end;
	bool			start_end;
}	t_ctx;

#endif
