/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:59:52 by Camille           #+#    #+#             */
/*   Updated: 2026/01/22 23:11:47 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_stdio.h"
#include "get_next_line.h"

void	error_exit(char *errmsg, int fd, char *row)
{
	ft_dprintf(2, "Error\n%s\n", errmsg);
	while (row)
	{
		free(row);
		row = get_next_line(fd);
	}
	if (fd >= 0)
		close(fd);
	exit(EXIT_FAILURE);
}
