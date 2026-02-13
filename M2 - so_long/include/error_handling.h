/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:24:35 by Camille           #+#    #+#             */
/*   Updated: 2026/02/12 22:14:33 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

# include "play.h"

# define ERRMSG_NO_PARAM \
	"The so_long program take a .ber file map as a parameter. [err0]"
# define ERRMSG_INVALID_EXTENSION \
	"The file extension is invalid (.ber required). [err1]"
# define ERRMSG_INVALID_PATH \
	"The file path is invalid or does not exist. [err2]"
# define ERRMSG_INVALID_MAP_OR_MALLOC_FAILED \
	"The map is not valid or the memory allocation has failed. [err3]"
# define ERRMSG_INVALID_SURROUNDING \
	"The map is not surrounded by walls. [err4]"
# define ERRMSG_SIZE_MIN \
	"The minimum size of the map can be 3x5, 4x4 or 5x3. [err5]"
# define ERRMSG_SIZE_MAX \
	"The maximum size of the map is 20x38. [err6]"
# define ERRMSG_MAP_IS_NOT_RECTANGULAR \
	"The map is not rectangular. [err7]"
# define ERRMSG_INVALID_MAP_CHARACTERS \
	"The characters in the map's data are not valid. [err8]"
# define ERRMSG_DUPLICATE_PLAYER \
	"There must be only one player on the map. [err9]"
# define ERRMSG_DUPLICATE_EXIT \
	"There must be only one exit on the map. [err10]"
# define ERRMSG_NO_COLLECTIBLE \
	"There must be at least one collectible on the map. [err11]"
# define ERRMSG_NO_PLAYER \
	"There must be one player on the map. [err12]"
# define ERRMSG_NO_EXIT \
	"There must be one exit on the map. [err13]"
# define ERRMSG_UNPLAYABLE_MAP \
	"The map is unplayable. [err14]"

void	error_exit(char *errmsg, int fd, char *row);
void	error_exit_mlx_malloc(t_mlx *mlx);
void	error_exit_mlx_image_malloc(t_game_engine *ge, mlx_image tilesets[]);

#endif
