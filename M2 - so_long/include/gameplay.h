/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 09:59:48 by Camille           #+#    #+#             */
/*   Updated: 2026/02/08 10:21:33 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEPLAY_H
# define GAMEPLAY_H

# include "map.h"
# include "play.h"

enum e_direction
{
	RIGHT,
	LEFT,
	DOWN,
	UP
};

bool	move_player(enum e_direction direction, t_map *map,
		t_component_position pos);
bool	update_game_status(t_game_engine *ge, bool player_move);

#endif
