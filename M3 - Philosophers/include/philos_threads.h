/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_threads.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <private_mail>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:16:48 by cboucher          #+#    #+#             */
/*   Updated: 2026/07/03 14:56:29 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_THREADS_H
# define PHILOS_THREADS_H

bool	create_philos_threads(t_philo *philos, int n);

bool	try_taking_fork(pthread_mutex_t *m_fork, bool *fork);

#endif
