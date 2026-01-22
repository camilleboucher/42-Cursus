/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:45:41 by Camille           #+#    #+#             */
/*   Updated: 2026/01/22 17:15:29 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error.h"
#include "map.h"

int	main(int argc, char *argv[])
{
	t_map	map;
	if (argc != 2)
		error(0, -1, (void *)0, 0);
	map = extract_map(argv[1]);
	(void)map; //FIX: tmp
	return (0);
}
