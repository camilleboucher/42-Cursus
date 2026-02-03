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

static void	init_mlx(t_mlx *mlx, int width, int height);

void	play(t_map *map)
{
	t_game_engine	ge;
	t_mlx			mlx;

	ge.map = map;
	init_mlx(&mlx, map->width * TILE_SIZE, map->height * TILE_SIZE);
	mlx_loop(mlx.ctx);
	(void)ge;
	mlx_destroy_window(mlx.ctx, mlx.win);
	mlx_destroy_context(mlx.ctx);
}

static void	init_mlx(t_mlx *mlx, int width, int height)
{
	mlx->ctx = mlx_init();
	mlx->info = (mlx_window_create_info){ 0 };
	mlx->info.title = WINDOW_TITLE;
	mlx->info.width = width;
	mlx->info.height = height;
	mlx->win = mlx_new_window(mlx->ctx, &mlx->info);
}
