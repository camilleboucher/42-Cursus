/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:45:41 by Camille           #+#    #+#             */
/*   Updated: 2026/01/22 23:12:28 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "ft_string.h"
#include "map.h"
#include "error_handling.h"

static bool	is_valid_extension(char *path, char *ext);

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
		error_exit(ERRMSG_NO_PARAM, -1, NULL);
	if (!is_valid_extension(argv[1], MAP_FILE_EXTENSION))
		error_exit(ERRMSG_INVALID_EXTENSION, -1, NULL);
	map = extract_map(argv[1]);
	(void)map; //FIX: tmp
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
