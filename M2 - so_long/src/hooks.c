/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:19:02 by Camille           #+#    #+#             */
/*   Updated: 2026/02/08 10:23:07 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_scancode.h>
#include <stdbool.h>
#include <stdint.h>
#include "mlx.h"
#include "ft_stdio.h"
#include "hooks.h"
#include "play.h"
#include "gameplay.h"

void	window_hook(int event, void *param)
{
	if (event == 0)
	{
		ft_printf("\nBye!\n");
		mlx_loop_end((mlx_context)param);
	}
}

void	key_hook(int key, void *param)
{
	t_game_engine	*ge;
	t_mlx			*mlx;
	t_map			*map;
	bool			player_move;

	ge = (t_game_engine *)param;
	mlx = ge->mlx;
	map = ge->map;
	player_move = false;
	if (key == SDL_SCANCODE_ESCAPE)
	{
		ft_printf("\nBye!\n");
		mlx_loop_end(mlx->ctx);
	}
	else if (key == SDL_SCANCODE_RIGHT || key == SDL_SCANCODE_D)
		player_move = move_player(RIGHT, map, map->player_pos);
	else if (key == SDL_SCANCODE_LEFT || key == SDL_SCANCODE_A)
		player_move = move_player(LEFT, map, map->player_pos);
	else if (key == SDL_SCANCODE_DOWN || key == SDL_SCANCODE_S)
		player_move = move_player(DOWN, map, map->player_pos);
	else if (key == SDL_SCANCODE_UP || key == SDL_SCANCODE_W)
		player_move = move_player(UP, map, map->player_pos);
	if (!update_game_status(ge, player_move))
		mlx_loop_end(mlx->ctx);
}
