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

static void	init_params(int (**print_param)(va_list, int), int *count)
{
	unsigned char	i;

	*count = 0;
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

/*static void	increment_params(const char **format, int *counter)
{
	(*format)++;
	(*counter)++;
}*/

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	(*print_param[127])(va_list, int);
	int		count;

	init_params(print_param, &count);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (print_param[(unsigned char)*format])
				count += print_param[(unsigned char)*format](args, 1);
			else
				count += ft_putchar_fd('%', 1);
		}
		else
			count += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
