/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_children_utils.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/11 12:16:41 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_CHILDREN_UTILS_H
# define CREATE_CHILDREN_UTILS_H

# include "pipex.h"

bool	skip_iofiles(int size, int *i, t_io_data *io);
void	close_pipe(t_cmd **cmds, int size, int i);
int		get_exit_code(int wstatus);

#endif
