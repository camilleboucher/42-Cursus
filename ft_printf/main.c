/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:31:25 by Camille           #+#    #+#             */
/*   Updated: 2025/11/10 18:43:35 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main()
{
	char	*s = NULL;

	printf("			(%d)	ft_printf\n", ft_printf("char		|%c|", '0'));
	printf("			(%d)	printf\n", printf("char		|%c|", '0'));

	printf("		(%d)	ft_printf\n", ft_printf("string		|%s|", s));
	printf("		(%d)	printf\n", printf("string		|%s|", s));

	printf("	(%d)	ft_printf\n", ft_printf("pointer		|%p|", &s));
	printf("	(%d)	printf\n", printf("pointer		|%p|", &s));
	
	printf("		(%d)	ft_printf\n", ft_printf("decimal		|%d|", INT_MIN));
	printf("		(%d)	printf\n", printf("decimal		|%d|", INT_MIN));

	printf("		(%d)	ft_printf\n", ft_printf("integer		|%i|", INT_MIN));
	printf("		(%d)	printf\n", printf("integer		|%i|", INT_MIN));

	printf("		(%d)	ft_printf\n", ft_printf("unsigned decimal		|%u|", -1));
	printf("		(%d)	printf\n", printf("unsigned decimal		|%u|", -1));

	return (0);
}

