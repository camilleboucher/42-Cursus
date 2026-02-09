/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:19:17 by Camille           #+#    #+#             */
/*   Updated: 2026/02/06 16:09:42 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include "mlx_extended.h"
#include "play.h"
#include "map.h"
#include "components.h"
#include "assets.h"

static enum e_tile	find_tile(t_map *map, uint8_t line, uint8_t col);
static void			render_tile(enum e_tile found, t_game_engine *ge,
						t_mlx *mlx, t_component_position *pos);

void	rendering(void *param)
{
	t_game_engine			*ge;
	t_mlx					*mlx;
	t_map					*map;
	t_component_position	pos;

	ge = (t_game_engine *)param;
	mlx = ge->mlx;
	map = ge->map;
	pos = (t_component_position){0};
	while (pos.x < map->height)
	{
		pos.y = 0;
		while (pos.y < map->width)
		{
			render_tile(EMPTY_SPACE, ge, mlx, &pos);
			render_tile(find_tile(map, pos.x, pos.y), ge, mlx, &pos);
			pos.y++;
		}
		pos.x++;
	}
	mlx_clear_window(mlx->ctx, mlx->win, (mlx_color){0});
	//FIX: faire un wrapper layers car fn name trop long
	mlx_put_transformed_image_to_window(mlx->ctx, mlx->win, ge->render, 0, 0, ge->scaling, ge->scaling, 0);
	mlx_put_transformed_image_to_window(mlx->ctx, mlx->win, ge->tiles[PLAYER_FRONT],
			((map->player_pos.x * TILE_SIZE) - 8) * ge->scaling,
			((map->player_pos.y * TILE_SIZE) - 18) * ge->scaling, ge->scaling, ge->scaling, 0);
}

static enum e_tile	find_tile(t_map *map, uint8_t line, uint8_t col)
{
	if (map->data[line][col] == C_WALL)
		return (WALL);
	else if (map->data[line][col] == C_COLLECTIBLE)
		return (COLLECTIBLE);
	else if (map->data[line][col] == C_EXIT)
		return (EXIT);
	else
		return (EMPTY_SPACE);
}

//TODO: pour fix bug de la macro, utiliser eventuellement
//mlx_pixel_put_array(mlx_context mlx, mlx_window win, int x, int y, mlx_color* pixels, size_t pixels_number);
//et update la macro
static void	render_tile(enum e_tile found, t_game_engine *ge,
				t_mlx *mlx, t_component_position *pos)
{
	mlx_color				color;
	mlx_image				tile;
	t_component_position	r;
	t_component_position	w;

	tile = ge->tiles[found];
	r.x = 0;
	w.x = pos->x * TILE_SIZE;
	while (r.x < TILE_SIZE)
	{
		r.y = 0;
		w.y = pos->y * TILE_SIZE;
		while (r.y < TILE_SIZE)
		{
			color = mlx_get_image_pixel(mlx->ctx, tile, r.y, r.x);
			if (color.a)
				mlx_set_image_pixel(mlx->ctx, ge->render, w.y, w.x, color);
			r.y++;
			w.y++;
		}
		r.x++;
		w.x++;
	}
}
