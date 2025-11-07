/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:52:35 by Camille           #+#    #+#             */
/*   Updated: 2025/11/07 19:18:00 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void	init_print_params(void (**print_param)(va_list));
static void	set_print_params(void (**print_param)(va_list));

int	ft_printf(const char *format, ...)
{
	va_list	args;
	void	(*print_param[256])(va_list);

	init_print_params(print_param);
	set_print_params(print_param);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (print_param[(unsigned char)*format])
				print_param[(unsigned char)*format](args);
			else
				write(1, "%", 1);
			format++;
		}
		write(1, format, 1);
		format++;
	}
	va_end(args);
	return (0);
}

static void	init_print_params(void (**print_param)(va_list))
{
	unsigned char	i;

	i = 255;
	while (i)
	{
		print_param[i] = 0;
		i--;
	}
	print_param[0] = 0;
}

static void	set_print_params(void (**print_param)(va_list))
{
	print_param['c'] = print_char;
	/*print_param['s'] = print_string;
	print_param['p'] = print_pointer;
	print_param['d'] = print_decimal;
	print_param['i'] = print_integer;
	print_param['u'] = print_unsigned_decimal;
	print_param['x'] = print_hexadecimal_lowercase;
	print_param['X'] = print_hexadecimal_uppercase;
	print_param['%'] = print_percent_sign;*/
}

void	print_char(va_list args)
{
	char	c;
	c = va_arg(args, int);
	write(1, &c, 1);
}
/*
void	print_string(va_list args)
{
	return ;
}

void	print_pointer(va_list args)
{
	return ;
}

void	print_decimal(va_list args)
{
	return ;
}

void	print_integer(va_list args)
{
	return ;
}

void	print_unsigned_decimal(va_list args)
{
	return ;
}

void	print_hexadecimal_lowercase(va_list args)
{
	return ;
}

void	print_hexadecimal_uppercase(va_list args)
{
	return ;
}

void	print_percent_sign(va_list args)
{
	return ;
}
*/
int	main()
{
	char	c = 'P';

	ft_printf("Coucou ceci est mon %c", c);
	return (0);
}
