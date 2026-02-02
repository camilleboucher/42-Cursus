/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:45:41 by Camille           #+#    #+#             */
/*   Updated: 2026/01/29 23:25:50 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "ft_string.h"
#include "components.h"
#include "map.h"
#include "error_handling.h"

static bool	is_valid_extension(char *path, char *ext);
static bool	is_playable_map(t_map map);
static void	flood_fill_algorithm(t_map *map, t_component_position cell_pos);

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
		error_exit(ERRMSG_NO_PARAM, -1, NULL);
	if (!is_valid_extension(argv[1], MAP_FILE_EXTENSION))
		error_exit(ERRMSG_INVALID_EXTENSION, -1, NULL);
	map = extract_map(argv[1]);
	if (!is_playable_map(map))
		error_exit(ERRMSG_UNPLAYABLE_MAP, -1, NULL);
	play(&map);
	return (EXIT_SUCCESS);
}

static bool	is_valid_extension(char *path, char *ext)
{
	uint8_t	size;

	size = ft_strlen(ext);
	while (*path)
		path++;
	path -= size;
	if (!ft_strncmp(path, ext, size))
		return (true);
	return (false);
}

static bool	is_playable_map(t_map map)
{
	if (!map.nb_collectible)
		error_exit(ERRMSG_NO_COLLECTIBLE, -1, NULL);
	flood_fill_algorithm(&map, map.starting_pos);
	if (!map.has_exit && !map.nb_collectible)
		return (true);
	return (false);
}

static void	flood_fill_algorithm(t_map *map, t_component_position cell_pos)
{
	char	cell;

	cell = map->data[cell_pos.y][cell_pos.x];
	if (cell != C_WALL)
	{
		if (cell == C_COLLECTIBLE)
			map->nb_collectible--;
		else if (cell == C_EXIT)
			map->has_exit = false;
		map->data[cell_pos.y][cell_pos.x] = C_WALL;
		flood_fill_algorithm(map,
			(t_component_position){cell_pos.x, cell_pos.y - 1});
		flood_fill_algorithm(map,
			(t_component_position){cell_pos.x, cell_pos.y + 1});
		flood_fill_algorithm(map,
			(t_component_position){cell_pos.x - 1, cell_pos.y});
		flood_fill_algorithm(map,
			(t_component_position){cell_pos.x + 1, cell_pos.y});
	}
}
