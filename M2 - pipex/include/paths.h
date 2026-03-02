/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/02 19:05:13 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHS_H
# define PATHS_H

# include "commands.h"

char	**extract_paths(t_cmd **cmds, int size, char *envp[]);
void	free_paths(char **paths);
void	error_paths_exit(t_cmd **cmds, int size, char **paths);

#endif
