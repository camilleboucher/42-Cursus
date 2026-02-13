/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:06:50 by Camille           #+#    #+#             */
/*   Updated: 2026/02/12 22:27:50 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include "ft_string.h"
#include "mlx.h"
#include "play.h"
#include "assets.h"
#include "components.h"
#include "error_handling.h"

static void			load_tilesets(t_game_engine *ge, t_mlx *mlx,
						mlx_image tilesets[]);
static mlx_image	load_from_tileset(t_component_position tile_pos,
						uint8_t tile_size, mlx_image *tileset, t_mlx *mlx);

void	load_tiles(t_game_engine *ge, t_mlx *mlx)
{
	mlx_image				tilesets[NB_TILESETS];

	load_tilesets(ge, mlx, tilesets);
	ge->tiles[EMPTY_SPACE] = load_from_tileset((t_component_position){2, 8},
			TILE_SIZE, &tilesets[TERRAIN], mlx);
	ge->tiles[WALL] = load_from_tileset((t_component_position){4, 1},
			TILE_SIZE, &tilesets[RESSOURCES], mlx);
	ge->tiles[COLLECTIBLE] = load_from_tileset((t_component_position){1, 10},
			TILE_SIZE, &tilesets[RESSOURCES], mlx);
	ge->tiles[EXIT] = load_from_tileset((t_component_position){8, 1},
			TILE_SIZE, &tilesets[RESSOURCES], mlx);
	ge->tiles[PLAYER_FRONT] = load_from_tileset((t_component_position){0, 0},
			TILE_PLAYER_SIZE, &tilesets[CHARACTER], mlx);
	if (!ge->tiles[EMPTY_SPACE] || !ge->tiles[WALL] || !ge->tiles[COLLECTIBLE]
		|| !ge->tiles[EXIT] || !ge->tiles[PLAYER_FRONT])
		error_exit_mlx_image_malloc(ge, tilesets);
	mlx_destroy_image(mlx->ctx, tilesets[TERRAIN]);
	mlx_destroy_image(mlx->ctx, tilesets[RESSOURCES]);
	mlx_destroy_image(mlx->ctx, tilesets[CHARACTER]);
}

static void	load_tilesets(t_game_engine *ge, t_mlx *mlx, mlx_image tilesets[])
{
	ft_memset(ge->tiles, 0x0, NB_TILE_TEXTURES * sizeof(mlx_image));
	ft_memset(tilesets, 0x0, NB_TILESETS * sizeof(mlx_image));
	tilesets[TERRAIN] = mlx_new_image_from_file(mlx->ctx,
			PATH_TILESET_TERRAIN, NULL, NULL);
	tilesets[RESSOURCES] = mlx_new_image_from_file(mlx->ctx,
			PATH_TILESET_OBSTACLES, NULL, NULL);
	tilesets[CHARACTER] = mlx_new_image_from_file(mlx->ctx,
			PATH_TILESET_CHARACTER, NULL, NULL);
	if (!tilesets[TERRAIN] || !tilesets[RESSOURCES] || !tilesets[CHARACTER])
		error_exit_mlx_image_malloc(ge, tilesets);
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
