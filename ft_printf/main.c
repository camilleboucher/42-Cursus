/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:31:25 by Camille           #+#    #+#             */
/*   Updated: 2025/11/08 18:08:23 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	char	*s = NULL;

	printf("			(%d)	ft_printf\n", ft_printf("char		|%c|", '0'));
	printf("			(%d)	printf\n", printf("char		|%c|", '0'));

	printf("		(%d)	ft_printf\n", ft_printf("string		|%s|", s));
	printf("		(%d)	printf\n", printf("string		|%s|", s));

	printf("			(%d)	ft_printf\n", ft_printf("pointer		|%p|", &s));
	printf("			(%d)	printf\n", printf("pointer		|%p|", &s));

	return (0);
}

