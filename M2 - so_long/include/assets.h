/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:13:54 by Camille           #+#    #+#             */
/*   Updated: 2026/02/12 21:20:59 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

# include "play.h"

# define NB_TILESETS 3
# define NB_TILE_TEXTURES 5
# define TILE_SIZE 16
# define TILE_PLAYER_SIZE 32

# define PATH_TILESET_TERRAIN "assets/tundraSwampTaigaForestDesert_0.png"
# define PATH_TILESET_OBSTACLES "assets/forest_ [resources].png"
# define PATH_TILESET_CHARACTER "assets/blue_haired_woman.png"

enum e_tileset
{
	TERRAIN,
	RESSOURCES,
	CHARACTER
};

enum e_tile
{
	EMPTY_SPACE,
	WALL,
	COLLECTIBLE,
	EXIT,
	PLAYER_FRONT
};

void		load_tiles(t_game_engine *ge, t_mlx *mlx);

#endif
