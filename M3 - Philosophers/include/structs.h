/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <private_mail>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 16:27:29 by cboucher          #+#    #+#             */
/*   Updated: 2026/06/29 12:26:22 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_philo
{
	int				id;
	struct timeval	hunger_death;
	int				total_meals;
	pthread_t		thread;
	pthread_mutex_t	m_fork;
	bool			fork;
	struct s_ctx	*ctx;
}	t_philo;

typedef struct s_ctx
{
	int		nb_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_times_must_eat;
	t_philo	*philos;
}	t_ctx;

#endif
