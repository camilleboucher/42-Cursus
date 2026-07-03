/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <private_mail>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:04:06 by cboucher          #+#    #+#             */
/*   Updated: 2026/07/03 14:24:08 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <sys/time.h>
# include <stdint.h>

int			ft_atoi(const char *nptr);

int			ft_isdigit(int c);
int			ft_aredigits(char *s);

void		add_milliseconds(struct timeval *tv, int ms_to_add);
uint64_t	get_timestamp_in_ms(struct timeval *tv);

#endif
