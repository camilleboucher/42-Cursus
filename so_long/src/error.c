/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:10:53 by Camille           #+#    #+#             */
/*   Updated: 2026/01/22 17:24:11 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "ft_printf.h"
#include <stdint.h>
#include <stdlib.h>

static char	*get_errno(uint8_t *errno);

void	error(uint8_t errno, int fd, void **malloc, uint8_t count)
{
	uint8_t	i;

	ft_printf("Error\n%s\n", get_errno(&errno));
	i = 0;
	while (i < count)
	{
		free(malloc[i]);
		i++;
	}
	exit(EXIT_FAILURE);
	if (fd >= 0)
		close(fd);
}

static char	*get_errno(uint8_t *errno)
{
	char	*err_msg[4];

	err_msg[0] = "The so_long program take a .ber file map as a parameter. [err0]";
	err_msg[1] = "The file extension is invalid (.ber required). [err1]";
	err_msg[2] = "The file path is invalid or does not exist. [err2]";
	err_msg[3] = "The map is not surrounded by walls. [err3]";
	return (err_msg[*errno]);
}
