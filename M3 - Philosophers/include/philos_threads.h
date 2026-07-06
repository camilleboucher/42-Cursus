/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_threads.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <private_mail>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:16:48 by cboucher          #+#    #+#             */
/*   Updated: 2026/07/05 17:21:35 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_THREADS_H
# define PHILOS_THREADS_H

bool	create_philos_threads(t_ctx *ctx, t_philo *philos, int n);

bool	is_dead(t_ctx *ctx, t_philo *philo);
void	thinking(t_ctx *ctx, t_philo *philo);
void	eating(t_ctx *ctx, t_philo *philo);
bool	sleeping(t_ctx *ctx, t_philo *philo);

void	try_taking_first_fork(t_ctx *ctx, int current, t_philo *philo);
void	try_taking_second_fork(t_ctx *ctx, int current, t_philo *philo);
void	put_forks_on_the_table(t_ctx *ctx, t_philo *philo);

#endif
