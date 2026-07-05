/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <private_mail>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 19:17:26 by cboucher          #+#    #+#             */
/*   Updated: 2026/07/03 11:54:13 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "utils.h"

void	add_milliseconds(struct timeval *tv, int ms_to_add)
{
	int64_t	us_total;

	if (ms_to_add <= 0)
		return ;
	us_total = (int64_t)tv->tv_usec + (int64_t)ms_to_add * 1000LL;
	tv->tv_sec += (time_t)(us_total / 1000000LL);
	tv->tv_usec = (suseconds_t)(us_total % 1000000LL);
}

uint64_t	get_timestamp_in_ms(struct timeval *tv, uint64_t delta)
{
	return ((uint64_t)tv->tv_sec * 1000LL + (uint64_t)tv->tv_usec / 1000LL
	- delta);
}

uint64_t	gettimeofday_in_ms(uint64_t delta)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (get_timestamp_in_ms(&tv, delta));
}
