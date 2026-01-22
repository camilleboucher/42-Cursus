/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:59:52 by Camille           #+#    #+#             */
/*   Updated: 2026/01/22 17:31:50 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>
#include "map.h"
#include "error.h"
#include "ft_string.h"
#include "get_next_line.h"

static bool	is_valid_extension(char *path, char *ext);
static t_map	parsing(int fd);

t_map	extract_map(char *path)
{
	int		fd;
	t_map	map;

	if (!is_valid_extension(path, "ber"))
		error(1, -1,(void *)0, 0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error(2, -1, (void *)0, 0);
	map = parsing(fd);
	return (map);
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

static t_map	parsing(int fd)
{
	t_map	map;
	char	*row;
	uint8_t	i;

	map = (t_map){0};
	row = get_next_line(fd);
	i = 0;
	while (row[i] || row[i] != '\n')
	{
		if (row[i] != '1')
			error(3, fd, (void *)&row, 1);
		i++;
	}
	return (map);
}
