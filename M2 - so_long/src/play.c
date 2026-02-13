/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:06:50 by Camille           #+#    #+#             */
/*   Updated: 2026/02/12 20:46:29 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_stdio.h"
#include "play.h"
#include "map.h"
#include "error_handling.h"
#include "hooks.h"
#include "assets.h"
#include "rendering.h"

static uint8_t		init_mlx_and_scaling(t_mlx *mlx, int width, int height);
static void			free_mlx(t_game_engine *ge, t_mlx *mlx);

void	play(t_map *map)
{
	t_game_engine	ge;
	t_mlx			mlx;
	mlx_image		tiles[NB_TILE_TEXTURES];

	ge.map = map;
	ge.mlx = &mlx;
	mlx = (t_mlx){0x0};
	ge.scaling = init_mlx_and_scaling(&mlx,
			map->width * TILE_SIZE, map->height * TILE_SIZE);
	ge.render = mlx_new_image(mlx.ctx, map->width * TILE_SIZE,
			map->height * TILE_SIZE);
	if (!ge.render)
		error_exit_mlx_malloc(&mlx);
	ge.tiles = tiles;
	load_tiles(&ge, &mlx);
	ge.move_count = 0;
	ft_printf("Move count : 0");
	mlx_on_event(mlx.ctx, mlx.win, MLX_KEYDOWN, key_hook, &ge);
	mlx_add_loop_hook(mlx.ctx, rendering, &ge);
	mlx_loop(mlx.ctx);
	free_mlx(&ge, &mlx);
}

static uint8_t	init_mlx_and_scaling(t_mlx *mlx, int width, int height)
{
	int		screen_width;
	int		screen_height;
	uint8_t	scaling;

	mlx->ctx = mlx_init();
	if (!mlx->ctx)
		error_exit_mlx_malloc(mlx);
	mlx->info = (mlx_window_create_info){0};
	mlx->info.title = WINDOW_TITLE;
	mlx->win = mlx_new_window(mlx->ctx, &mlx->info);
	if (!mlx->win)
		error_exit_mlx_malloc(mlx);
	mlx_get_screen_size(mlx->ctx, mlx->win, &screen_width, &screen_height);
	if (screen_width <= 1920)
		scaling = 3;
	else if (screen_width >= 3840)
		scaling = 5;
	else
		scaling = 4;
	mlx->info.width = width * scaling;
	mlx->info.height = height * scaling;
	mlx_set_window_size(mlx->ctx, mlx->win, mlx->info.width, mlx->info.height);
	mlx_set_fps_goal(mlx->ctx, FPS);
	mlx_on_event(mlx->ctx, mlx->win, MLX_WINDOW_EVENT, window_hook, mlx->ctx);
	return (scaling);
}

static void	free_mlx(t_game_engine *ge, t_mlx *mlx)
{
	uint8_t	i;

	i = 0;
	while (i < NB_TILE_TEXTURES)
	{
		mlx_destroy_image(mlx->ctx, ge->tiles[i]);
		i++;
	}
	mlx_destroy_image(mlx->ctx, ge->render);
	mlx_destroy_window(mlx->ctx, mlx->win);
	mlx_destroy_context(mlx->ctx);
}
