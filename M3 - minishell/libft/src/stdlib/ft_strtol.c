/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:58:31 by Camille           #+#    #+#             */
/*   Updated: 2026/05/07 17:14:36 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_ctype.h"
#include "ft_string.h"
#include <stdbool.h>

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static char	*skip_space(char *nptr)
{
	while (ft_isspace(*nptr))
		nptr++;
	return (nptr);
}

static bool	number_is_min(char *nptr)
{
	if (ft_strlen(nptr) == 20 && !ft_strncmp(nptr, "-9223372036854775808", 20))
		return (true);
	return (false);
}

static char	*skip_sign_and_set(char *nptr, int *sign)
{
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			*sign = -1;
		nptr++;
	}
	return (nptr);
}

long	ft_strtol(char *nptr, char **endptr)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	*endptr = NULL;
	nptr = skip_space(nptr);
	if (number_is_min(nptr))
		return (-9223372036854775807 - 1);
	nptr = skip_sign_and_set(nptr, &sign);
	while (ft_isdigit(*nptr))
	{
		if (nbr * 10 + (*nptr - '0') < 0)
		{
			*endptr = (char *)nptr;
			break ;
		}
		nbr *= 10;
		nbr += *nptr - '0';
		nptr++;
	}
	return (nbr * sign);
}
