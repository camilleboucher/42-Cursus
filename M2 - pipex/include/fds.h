/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/07 15:18:52 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDS_H
# define FDS_H

# include "pipex.h"

void	get_fds_io(t_cmd **cmds, int size, t_io_data *io);
void	get_fds(t_cmd **cmds, int size, int i, t_io_data *io);
void	duplicate_fds(t_cmd *cmd);
void	close_fds(int (*fds)[2]);
void	close_all(t_cmd **cmds, int size);

#endif
