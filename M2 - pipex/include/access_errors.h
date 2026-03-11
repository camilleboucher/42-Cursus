/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_errors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/11 23:09:18 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCESS_ERRORS_H
# define ACCESS_ERRORS_H

# include "pipex.h"

int		access_and_wait_children(t_cmd **cmds, int size, t_io_data *io);
void	wait_and_print_errors_access(t_io_data *io, int fd_errors_access);

#endif
