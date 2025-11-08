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

void	print_pointer(va_list args)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_fd(va_arg(args, size_t), "0123456789abcdef", 16, 1);
}
