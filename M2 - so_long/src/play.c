/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:06:50 by Camille           #+#    #+#             */
/*   Updated: 2026/02/02 17:56:48 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play.h"
#include "map.h"
#include "mlx.h"

void	init_mlx(t_game_engine *ge);

void	play(t_map *map)
{
	t_game_engine	ge;

	ge.map = map;
	init_mlx(&ge);
}

void	init_mlx(t_game_engine *ge)
{
	t_mlx	mlx;

	mlx.mlx
}
