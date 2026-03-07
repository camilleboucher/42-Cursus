/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/02 15:05:11 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include <unistd.h>

# define IN 0
# define OUT 1

typedef struct s_cmd
{
	char	*path;
	char	**argv;
	int		fds[2];
	pid_t	pid;
}	t_cmd;

void	get_cmds(t_cmd **cmds, int size, char *argv[], char *envp[]);

#endif
