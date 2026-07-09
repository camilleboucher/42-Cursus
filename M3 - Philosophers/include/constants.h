/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <private_mail>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:27:53 by cboucher          #+#    #+#             */
/*   Updated: 2026/06/27 22:43:22 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define USAGE_MSG1 "Usage: philo need at least 4 positive numeric arguments "
# define USAGE_MSG2 "separated by spaces:\nnumber_of_philosophers time_to_die "
# define USAGE_MSG3 "time_to_eat time_to_sleep "
# define USAGE_MSG4 "[number_of_times_each_philosopher_must_eat]\n"

# define USAGE_MAX_LIMIT_MSG "Warning: the maximum limit set is 120000\n"

# define EXIT_BAD_ARGS 2

# define THINKING_MSG "\x1b[38:5:82m%zu %d is thinking\x1b[0m\n"
# define FORK_MSG "\x1b[38:5:214m%zu %d has taken a fork\x1b[0m\n"
# define EATING_MSG "\x1b[38:5:213m%zu %d is eating\x1b[0m\n"
# define SLEEPING_MSG "\x1b[38:5:50m%zu %d is sleeping\x1b[0m\n"
# define DYING_MSG "\x1b[38:5:196m%zu %d died\x1b[0m\n"

#endif
