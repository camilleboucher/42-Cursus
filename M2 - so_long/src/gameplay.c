/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 09:41:19 by Camille           #+#    #+#             */
/*   Updated: 2026/02/08 10:43:46 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "gameplay.h"
#include "map.h"

bool	move_player(enum e_direction direction, t_map *map,
				t_component_position pos)
{
	if (direction == RIGHT && map->data[pos.y][pos.x + 1] != C_WALL)
	{
		map->player_pos.x++;
		return (true);
	}
	else if (direction == LEFT && map->data[pos.y][pos.x - 1] != C_WALL)
	{
		map->player_pos.x--;
		return (true);
	}
	else if (direction == DOWN && map->data[pos.y + 1][pos.x] != C_WALL)
	{
		map->player_pos.y++;
		return (true);
	}
	else if (direction == UP && map->data[pos.y - 1][pos.x] != C_WALL)
	{
		map->player_pos.y--;
		return (true);
	}
	return (false);
}

bool	update_game_status(t_game_engine *ge, bool player_move)
{
	char		*player_cell;

	player_cell = &ge->map->data[ge->map->player_pos.y][ge->map->player_pos.x];
	if (player_move)
	{
		ge->move_count++;
		ft_printf("\rMove count : %d", ge->move_count);
	}
	if (*player_cell == C_COLLECTIBLE)
	{
		ge->map->nb_collectible--;
		*player_cell = C_EMPTY_SPACE;
	}
	else if (!(ge->map->nb_collectible) && *player_cell == C_EXIT)
	{
		ft_printf("\rMove count : %d\nCongratulation! You win!\n",
			ge->move_count);
		return (false);
	}
	return (true);
}
