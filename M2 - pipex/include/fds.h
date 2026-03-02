/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/02 15:34:46 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDS_H
# define FDS_H

# include "commands.h"

void	get_fds(t_cmd **cmds, int size, char *infile, char *outfile);
void	close_fds(t_cmd **cmds, int size);//TODO: non utilise pour le moment

#endif
