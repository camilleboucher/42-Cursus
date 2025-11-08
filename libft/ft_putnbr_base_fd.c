/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:11:00 by Camille           #+#    #+#             */
/*   Updated: 2025/11/08 15:27:26 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	ft_putnbr_base_fd(size_t n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
		return ;
	}
	else if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}*/

void	ft_putnbr_base_fd(size_t n, char *base, size_t base_size, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_base_fd(-n, base, base_size, fd);
		return ;
	}
	else if (n >= base_size)
		ft_putnbr_base_fd(n / base_size, base, base_size, fd);
	ft_putchar_fd(base[n % base_size], fd);
}
