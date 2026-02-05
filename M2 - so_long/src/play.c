/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:06:50 by Camille           #+#    #+#             */
/*   Updated: 2026/02/05 11:51:01 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <sys/time.h>
#include "mlx.h"
#include "play.h"
#include "map.h"
#include "hooks.h"
#include "assets.h"
#include "components.h"

static void	init_mlx(t_mlx *mlx, int width, int height);
static void	load_tiles(t_game_engine *ge, t_mlx *mlx);
static mlx_image	load_tile_from_tileset(uint8_t line, uint8_t column,
										mlx_image *tileset, t_mlx *mlx);

void	rendering(void *param)//FIX:CONTINUER RENDERING
{
	t_game_engine	*ge;
	t_mlx			*mlx;

	ge = (t_game_engine *)param;
	mlx = ge->mlx;
	mlx_put_image_to_window(mlx->ctx, mlx->win, ge->tiles[EMPTY_SPACE], 0, 0);
	mlx_put_image_to_window(mlx->ctx, mlx->win, ge->tiles[WALL], 16, 0);
	mlx_put_image_to_window(mlx->ctx, mlx->win, ge->tiles[COLLECTIBLE], 32, 0);
	mlx_put_image_to_window(mlx->ctx, mlx->win, ge->tiles[EXIT], 48, 0);
}

void	play(t_map *map)
{
	t_game_engine	ge;
	t_mlx			mlx;
	mlx_image		tiles[NB_TILE_TEXTURES];

	ge.map = map;
	ge.mlx = &mlx;//INFO:peut etre pas necessaire
	ge.tiles = tiles;
	init_mlx(&mlx, map->width * TILE_SIZE, map->height * TILE_SIZE);
	load_tiles(&ge, &mlx);
	mlx_add_loop_hook(mlx.ctx, rendering, &ge);
	mlx_loop(mlx.ctx);
	//TODO: DESTROY TILES
	mlx_destroy_window(mlx.ctx, mlx.win);
	mlx_destroy_context(mlx.ctx);
}

static void	init_mlx(t_mlx *mlx, int width, int height)
{
	mlx->ctx = mlx_init();
	mlx->info = (mlx_window_create_info){0};
	mlx->info.title = WINDOW_TITLE;
	mlx->info.width = width;
	mlx->info.height = height;
	mlx->win = mlx_new_window(mlx->ctx, &mlx->info);
	mlx_set_fps_goal(mlx->ctx, FPS);
	mlx_on_event(mlx->ctx, mlx->win, MLX_WINDOW_EVENT, window_hook, mlx->ctx);
	mlx_on_event(mlx->ctx, mlx->win, MLX_KEYDOWN, key_hook, mlx->ctx);
}

static void	load_tiles(t_game_engine *ge, t_mlx *mlx)
{
	mlx_image	tileset[NB_TILESETS];

	tileset[TERRAIN] = mlx_new_image_from_file(mlx->ctx, PATH_TILESET_TERRAIN,
											NULL, NULL);
	tileset[RESSOURCES] = mlx_new_image_from_file(mlx->ctx, PATH_TILESET_OBSTACLES,
											NULL, NULL);
	ge->tiles[EMPTY_SPACE] = load_tile_from_tileset(2, 2, &tileset[TERRAIN], mlx);
	ge->tiles[WALL] = load_tile_from_tileset(4, 1, &tileset[RESSOURCES], mlx);
	ge->tiles[COLLECTIBLE] = load_tile_from_tileset(1, 10, &tileset[RESSOURCES], mlx);
	ge->tiles[EXIT] = load_tile_from_tileset(8, 1, &tileset[RESSOURCES], mlx);
	//TODO: DESTROY TILESETS
}

static mlx_image	load_tile_from_tileset(uint8_t line, uint8_t column,
										mlx_image *tileset, t_mlx *mlx)
{
	mlx_image				tile;
	mlx_color				color;
	t_component_position	r;
	t_component_position	w;
	
	tile = mlx_new_image(mlx->ctx, TILE_SIZE, TILE_SIZE);
	line *= TILE_SIZE;
	column *= TILE_SIZE;
	r.x = line;
	w.x = 0;
	while (r.x < (line + TILE_SIZE))
	{
		r.y = column;
		w.y = 0;
		while (r.y < (column + TILE_SIZE))
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
