/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:15:36 by Camille           #+#    #+#             */
/*   Updated: 2025/10/31 16:28:46 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-214748364", 10);
		ft_putnbr(8);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
		return ;
	}
	else if (nb >= 10)
		ft_putnbr(nb / 10);
	putchar((nb % 10) + '0');
}*/

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	
	if (!n)
		return
	i = 0;
	while (i )
}
