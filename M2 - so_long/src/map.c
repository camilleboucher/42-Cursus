/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:59:52 by Camille           #+#    #+#             */
/*   Updated: 2026/02/06 15:54:54 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include "error_handling.h"
#include "map.h"

static void	parsing(int fd, t_map *map);
static bool	check_first_last_rows(char *row, t_map *map);
static void	check_rows(char *row, t_map *map, int fd);
static void	check_duplicate(uint8_t i, t_map *map, char *row, int fd);

t_map	extract_map(char *path)
{
	int		fd;
	t_map	map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit(ERRMSG_INVALID_PATH, -1, NULL);
	map = (t_map){0};
	parsing(fd, &map);
	close(fd);
	return (map);
}

static void	parsing(int fd, t_map *map)
{
	char	*row;

	row = get_next_line(fd);
	if (!row)
		error_exit(ERRMSG_INVALID_MAP_OR_MALLOC_FAILED, fd, NULL);
	if (!check_first_last_rows(row, map))
		error_exit(ERRMSG_INVALID_SURROUNDING, fd, row);
	if (map->width < 3)
		error_exit(ERRMSG_SIZE_MIN, fd, row);
	free(row);
	map->height++;
	row = get_next_line(fd);
	while (row)
	{
		check_rows(row, map, fd);
		free(row);
		row = get_next_line(fd);
	}
	if (!check_first_last_rows(map->data[map->height - 1], NULL))
		error_exit(ERRMSG_INVALID_SURROUNDING, fd, NULL);
}

static bool	check_first_last_rows(char *row, t_map *map)
{
	uint8_t	i;

	i = 0;
	while (row[i] && row[i] != '\n')
	{
		if (row[i] != C_WALL)
			return (false);
		if (map)
			map->data[map->height][i] = C_WALL;
		i++;
	}
	if (map && !map->width)
		map->width = i;
	return (true);
}

static void	check_rows(char *row, t_map *map, int fd)
{
	uint8_t	i;

	i = 0;
	if (row[i] != C_WALL)
		error_exit(ERRMSG_INVALID_SURROUNDING, fd, row);
	map->data[map->height][i] = row[i];
	i++;
	while (row[i] && row[i] != '\n')
	{
		if (row[i] != C_EMPTY_SPACE && row[i] != C_WALL
			&& row[i] != C_COLLECTIBLE && row[i] != C_EXIT
			&& row[i] != C_PLAYER_STARTING_POS)
			error_exit(ERRMSG_INVALID_MAP_CHARACTERS, fd, row);
		if (row[i] == C_COLLECTIBLE)
			map->nb_collectible++;
		else if (row[i] == C_PLAYER_STARTING_POS || row[i] == C_EXIT)
			check_duplicate(i, map, row, fd);
		map->data[map->height][i] = row[i];
		i++;
	}
	if (i != map->width)
		error_exit(ERRMSG_MAP_IS_NOT_RECTANGULAR, fd, row);
	if (map->data[map->height][i - 1] != C_WALL)
		error_exit(ERRMSG_INVALID_SURROUNDING, fd, row);
	map->height++;
}

static void	check_duplicate(uint8_t i, t_map *map, char *row, int fd)
{
	if (row[i] == C_PLAYER_STARTING_POS)
	{
		if (map->player_pos.x)
			error_exit(ERRMSG_DUPLICATE_PLAYER, fd, row);
		map->player_pos.x = i;
		map->player_pos.y = map->height;
	}
	else
	{
		if (map->has_exit)
			error_exit(ERRMSG_DUPLICATE_EXIT, fd, row);
		map->has_exit = true;
	}
}
