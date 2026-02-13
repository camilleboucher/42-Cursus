/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:37:41 by Camille           #+#    #+#             */
/*   Updated: 2026/02/06 14:54:04 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAY_H
# define PLAY_H

# include <stdint.h>
# include "map.h"
# include "mlx.h"

# define WINDOW_TITLE "SO_LONG"
# define FPS 28

typedef struct s_mlx
{
	mlx_context				ctx;
	mlx_window_create_info	info;
	mlx_window				win;
}	t_mlx;

typedef struct s_game_engine
{
	t_map		*map;
	t_mlx		*mlx;
	uint8_t		scaling;
	mlx_image	render;
	mlx_image	*tiles;
	uint16_t	move_count;
}	t_game_engine;

void	play(t_map *map);

#endif
