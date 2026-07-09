/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_threads.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <private_mail>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:16:48 by cboucher          #+#    #+#             */
/*   Updated: 2026/07/09 18:49:21 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_THREADS_H
# define PHILOS_THREADS_H

bool	create_philos_threads(t_ctx *ctx, t_philo *philos, int n);

bool	is_dead(t_ctx *ctx, t_philo *philo);
void	waiting_rules(t_ctx *ctx, t_philo *philo, bool *first_loop);
void	lock_stdout_and_startend(t_ctx *ctx);
void	unlock_stdout_and_startend(t_ctx *ctx);
void	thinking(t_ctx *ctx, t_philo *philo, bool *first_loop);
bool	eating(t_ctx *ctx, t_philo *philo);
bool	sleeping(t_ctx *ctx, t_philo *philo);

void	try_taking_first_fork(t_ctx *ctx, t_philo *philo, int next_n);
void	try_taking_second_fork(t_ctx *ctx, t_philo *philo, int next_n);
void	put_forks_on_the_table(t_ctx *ctx, t_philo *philo);

#endif
