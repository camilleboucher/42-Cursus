/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:06:50 by Camille           #+#    #+#             */
/*   Updated: 2026/02/08 10:06:54 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include "mlx.h"
#include "ft_stdio.h"
#include "play.h"
#include "map.h"
#include "hooks.h"
#include "assets.h"
#include "components.h"
#include "rendering.h"

static uint8_t		init_mlx_and_scaling(t_mlx *mlx, int width, int height);
static void			load_tiles(t_game_engine *ge, t_mlx *mlx);
static mlx_image	load_from_tileset(t_component_position tile_pos,
						uint8_t tile_size, mlx_image *tileset, t_mlx *mlx);

void	play(t_map *map)
{
	t_game_engine	ge;
	t_mlx			mlx;
	mlx_image		tiles[NB_TILE_TEXTURES];
	uint8_t			i;

	ge.map = map;
	ge.mlx = &mlx;
	ge.scaling = init_mlx_and_scaling(&mlx, map->width * TILE_SIZE,
		map->height * TILE_SIZE);
	ge.tiles = tiles;
	load_tiles(&ge, &mlx);
	ge.render = mlx_new_image(mlx.ctx, map->width * TILE_SIZE,
			map->height * TILE_SIZE);
	ge.move_count = 0;
	ft_printf("Move count : 0");
	mlx_on_event(mlx.ctx, mlx.win, MLX_KEYDOWN, key_hook, &ge);
	mlx_add_loop_hook(mlx.ctx, rendering, &ge);
	mlx_loop(mlx.ctx);
	i = 0;
	while (i < NB_TILE_TEXTURES)
		mlx_destroy_image(mlx.ctx, tiles[i++]);
	mlx_destroy_image(mlx.ctx, ge.render);
	mlx_destroy_window(mlx.ctx, mlx.win);
	mlx_destroy_context(mlx.ctx);
}

static uint8_t	init_mlx_and_scaling(t_mlx *mlx, int width, int height)
{
	int		screen_width;
	int		screen_height;
	uint8_t	scaling;

	mlx->ctx = mlx_init();
	mlx->info = (mlx_window_create_info){0};
	mlx->info.title = WINDOW_TITLE;
	mlx->win = mlx_new_window(mlx->ctx, &mlx->info);
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

static void	load_tiles(t_game_engine *ge, t_mlx *mlx)
{
	mlx_image				tileset[NB_TILESETS];

	tileset[TERRAIN] = mlx_new_image_from_file(mlx->ctx,
			PATH_TILESET_TERRAIN, NULL, NULL);
	tileset[RESSOURCES] = mlx_new_image_from_file(mlx->ctx,
			PATH_TILESET_OBSTACLES, NULL, NULL);
	tileset[CHARACTER] = mlx_new_image_from_file(mlx->ctx,
			PATH_TILESET_CHARACTER, NULL, NULL);
	ge->tiles[EMPTY_SPACE] = load_from_tileset((t_component_position){2, 8}, TILE_SIZE,
											&tileset[TERRAIN], mlx);
	ge->tiles[WALL] = load_from_tileset((t_component_position){4, 1}, TILE_SIZE,
									 &tileset[RESSOURCES], mlx);
	ge->tiles[COLLECTIBLE] = load_from_tileset((t_component_position){1, 10}, TILE_SIZE,
			&tileset[RESSOURCES], mlx);
	ge->tiles[EXIT] = load_from_tileset((t_component_position){8, 1}, TILE_SIZE,
									&tileset[RESSOURCES], mlx);
	ge->tiles[PLAYER_FRONT] = load_from_tileset((t_component_position){0, 0}, TILE_PLAYER_SIZE,
			&tileset[CHARACTER], mlx);
	mlx_destroy_image(mlx->ctx, tileset[TERRAIN]);
	mlx_destroy_image(mlx->ctx, tileset[RESSOURCES]);
	mlx_destroy_image(mlx->ctx, tileset[CHARACTER]);
}

static mlx_image	load_from_tileset(t_component_position tile_pos,
										uint8_t tile_size, mlx_image *tileset, t_mlx *mlx)
{
	mlx_image				tile;
	mlx_color				color;
	t_component_position	r;
	t_component_position	w;

	tile = mlx_new_image(mlx->ctx, tile_size, tile_size);
	tile_pos.x *= tile_size;
	tile_pos.y *= tile_size;
	r.x = tile_pos.x;
	w.x = 0;
	while (r.x < (tile_pos.x + tile_size))
	{
		r.y = tile_pos.y;
		w.y = 0;
		while (r.y < (tile_pos.y + tile_size))
		{
			color = mlx_get_image_pixel(mlx->ctx, *tileset, r.y, r.x);
			mlx_set_image_pixel(mlx->ctx, tile, w.y, w.x, color);
			r.y++;
			w.y++;
		}
		r.x++;
		w.x++;
	}
	return (tile);
}
