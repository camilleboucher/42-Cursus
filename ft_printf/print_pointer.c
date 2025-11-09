/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:52:35 by Camille           #+#    #+#             */
/*   Updated: 2025/11/08 18:01:30 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	print_pointer(va_list args, int fd)
{
	size_t	address;
	int		zero_to_print;

	address = va_arg(args, size_t);
	if (!address)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	ft_putstr_fd("0x", fd);
	zero_to_print = 12 - ft_putnbr_base_fd(address, "0123456789abcdef", 16, -1);
	printf("%d", zero_to_print);
	while (zero_to_print)
	{
		ft_putchar_fd('0', 1);
		zero_to_print--;
	}
	ft_putnbr_base_fd(address, "0123456789abcdef", 16, fd);
	return (14);
}
