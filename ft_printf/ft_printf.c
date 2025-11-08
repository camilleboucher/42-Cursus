/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:52:35 by Camille           #+#    #+#             */
/*   Updated: 2025/11/08 15:31:09 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_print_params(void (**print_param)(va_list))
{
	unsigned char	i;

	i = 127;
	while (i)
	{
		i--;
		print_param[i] = 0;
	}
	print_param['c'] = print_char;
	print_param['s'] = print_string;
	print_param['p'] = print_pointer;
	/*print_param['d'] = print_decimal;
	print_param['i'] = print_integer;
	print_param['u'] = print_unsigned_decimal;
	print_param['x'] = print_hexadecimal_lowercase;
	print_param['X'] = print_hexadecimal_uppercase;
	print_param['%'] = print_percent_sign;*/
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	void	(*print_param[127])(va_list);

	init_print_params(print_param);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (print_param[(unsigned char)*format])
			{
				print_param[(unsigned char)*format](args);
				format++;
			}
			else
				ft_putchar_fd('%', 1);
		}
		ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (0);
}
