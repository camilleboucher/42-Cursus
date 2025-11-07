/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:14:22 by Camille           #+#    #+#             */
/*   Updated: 2025/11/07 17:54:40 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *format, ...);

void	print_char(va_list args);
void	print_string(va_list args);
void	print_pointer(va_list args);
void	print_decimal(va_list args);
void	print_integer(va_list args);
void	print_unsigned_decimal(va_list args);
void	print_hexadecimal_lowercase(va_list args);
void	print_hexadecimal_uppercase(va_list args);
void	print_percent_sign(va_list args);

#endif
