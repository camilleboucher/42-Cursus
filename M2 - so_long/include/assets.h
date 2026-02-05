/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:13:54 by Camille           #+#    #+#             */
/*   Updated: 2026/02/05 11:44:15 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

# define NB_TILESETS 3
# define NB_TILE_TEXTURES 5
# define TILE_SIZE 16

# define PATH_TILESET_TERRAIN "assets/tundraSwampTaigaForestDesert_0.png"
# define PATH_TILESET_OBSTACLES "assets/forest_ [resources].png"

enum e_tileset
{
	TERRAIN,
	RESSOURCES
};

enum e_tile
{
	EMPTY_SPACE,
	WALL,
	COLLECTIBLE,
	EXIT,
	PLAYER_FRONT
};

#endif
