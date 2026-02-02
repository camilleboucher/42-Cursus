/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:37:41 by Camille           #+#    #+#             */
/*   Updated: 2026/02/02 17:56:47 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAY_H
# define PLAY_H

# include "map.h"
# include "mlx.h"

# define WINDOW_TITLE "SO_LONG"
# define WINDOW_WIDTH 400
# define WINDOW_HEIGHT 400

typedef struct s_game_engine
{
	t_map	*map;
	t_mlx	*mlx;
}	t_game_engine;

typedef struct s_mlx
{
	mlx_context				ctx;
	mlx_window_create_info	info;
}	t_mlx;

#endif
