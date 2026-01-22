/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:59:52 by Camille           #+#    #+#             */
/*   Updated: 2026/01/22 23:45:40 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdint.h>
#include <fcntl.h>
#include "ft_string.h"
#include "get_next_line.h"
#include "error_handling.h"
#include "map.h"

static bool	is_valid_extension(char *path, char *ext);
static t_map	parsing(int fd);

t_map	extract_map(char *path)
{
	int		fd;
	t_map	map;

	if (!is_valid_extension(path, "ber"))
		error_exit(ERRMSG_INVALID_EXTENSION);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit(ERRMSG_INVALID_PATH);
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
	while (row[i] && row[i] != '\n')
	{
		if (row[i] != '1')
			error_exit(ERRMSG_INVALID_SURROUNDING);
		i++;
	}
	//if (i < 4)
		//error pas assez de colonnes
	// nb colonnes = i - 1;
	// nb row
	// free line and calculer le nb de line ou faire un buffer de lignes directement dans map
	return (map);
}
