/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:24:35 by Camille           #+#    #+#             */
/*   Updated: 2026/01/22 22:54:52 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

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
# define ERRMSG_MAP_IS_NOT_RECTANGULAR \
	"The map is not rectangular. [err6]"
# define ERRMSG_INVALID_MAP_CHARACTERS \
	"The characters in the map's data are not valid. [err7]"

void	error_exit(char *errmsg, int fd, char *row);

#endif
