/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/06 13:20:07 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "commands.h"

typedef struct s_io_data
{
	int		fd_infile;
	char	*outfile_path;
	int		outfile_flags;
}	t_io_data;

void	clean_pipex(t_cmd **cmds, int size);
void	error_exit(t_cmd **cmds, int size);

#endif
