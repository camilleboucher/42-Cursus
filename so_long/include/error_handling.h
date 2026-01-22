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

# define ERRMSG_NO_PARAM "The so_long program take a .ber file map as a parameter. [err0]"
# define ERRMSG_INVALID_EXTENSION "The file extension is invalid (.ber required). [err1]"
# define ERRMSG_INVALID_PATH "The file path is invalid or does not exist. [err2]"
# define ERRMSG_INVALID_SURROUNDING "The map is not surrounded by walls. [err3]"

void	error_exit(char *errmsg);

#endif
