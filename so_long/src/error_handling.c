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
#include "ft_stdio.h"

void	error_exit(char *errmsg)
{
	ft_dprintf(2, "Error\n%s\n", errmsg);//TODO: update old projects + bug ?
	exit(EXIT_FAILURE);
}
