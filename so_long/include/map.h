/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:10:43 by Camille           #+#    #+#             */
/*   Updated: 2026/01/29 17:24:44 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdint.h>
# include <stdbool.h>
# include "components.h"

# define MAP_FILE_EXTENSION "ber"

# define MAP_MAX_ROWS 255
# define MAP_MAX_COLS 255

# define C_EMPTY_SPACE '0'
# define C_WALL '1'
# define C_COLLECTIBLE 'C'
# define C_EXIT 'E'
# define C_PLAYER_STARTING_POS 'P'

typedef struct s_map
{
	uint8_t					width;
	uint8_t					height;
	char					data[MAP_MAX_ROWS][MAP_MAX_COLS];
	t_component_position	starting_pos;
	uint16_t				nb_collectible;
	bool					has_exit;
}	t_map;

t_map	extract_map(char *path);

#endif
