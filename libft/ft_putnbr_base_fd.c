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

int	ft_putnbr_base_fd(size_t n, char *base, size_t base_size, int fd)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		if (fd >= 0)
			ft_putchar_fd('-', fd);
		count++;
		count += ft_putnbr_base_fd(-n, base, base_size, fd);
		return (count);
	}
	else if (n >= base_size)
		count += ft_putnbr_base_fd(n / base_size, base, base_size, fd);
	if (fd >= 0)
		count += ft_putchar_fd(base[n % base_size], fd);
	count++;
	return (count);
}
