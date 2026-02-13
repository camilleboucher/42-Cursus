/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:59:52 by Camille           #+#    #+#             */
/*   Updated: 2026/02/12 22:18:15 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "assets.h"
#include "mlx.h"
#include "ft_stdio.h"
#include "get_next_line.h"
#include "play.h"

void	error_exit(char *errmsg, int fd, char *row)
{
	ft_dprintf(2, "Error\n%s\n", errmsg);
	while (row)
	{
		free(row);
		row = get_next_line(fd);
	}
	if (fd >= 0)
		close(fd);
	exit(EXIT_FAILURE);
}

void	error_exit_mlx_malloc(t_mlx *mlx)
{
	ft_dprintf(2, "Error\nMLX malloc has failed.\n");
	if (mlx->win)
		mlx_destroy_window(mlx->ctx, mlx->win);
	if (mlx->ctx)
		mlx_destroy_context(mlx->ctx);
	exit(EXIT_FAILURE);
}

void	error_exit_mlx_image_malloc(t_game_engine *ge, mlx_image tilesets[])
{
	t_mlx		*mlx;
	mlx_image	*tiles;
	uint8_t		i;

	mlx = ge->mlx;
	tiles = ge->tiles;
	mlx_destroy_image(mlx->ctx, ge->render);
	i = 0;
	while (i < NB_TILESETS)
	{
		if (tilesets[i])
			mlx_destroy_image(mlx->ctx, tilesets[i]);
		i++;
	}
	i = 0;
	while (i < NB_TILE_TEXTURES)
	{
		if (tiles[i])
			mlx_destroy_image(mlx->ctx, tiles[i]);
		i++;
	}
	error_exit_mlx_malloc(mlx);
}
