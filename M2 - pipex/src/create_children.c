/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_children.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/06 14:19:16 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "ft_stdio.h"
#include "pipex.h"
#include "fds.h"

void	make_love(t_cmd **cmds, int size, char *envp[])
{
	int	i;

	i = 0;
	if (!cmds[i]->path) //INFO: IGNORE de la premiere cmd si infile non valid
		i++;
	while (i < size)
	{
		cmds[i]->pid = fork();
		if (cmds[i]->pid == -1)//TODO: tester bash avec ulimit -u 1 conseil de mickael
			error_exit(cmds, size);
		if (!cmds[i]->pid)
		{
			if (cmds[i]->fds[IN] != -1)
				dup2(cmds[i]->fds[IN], STDIN_FILENO);
			dup2(cmds[i]->fds[OUT], STDOUT_FILENO);
			close_all_fds(cmds, size);
			if (execve(cmds[i]->path, cmds[i]->argv, envp) == -1)
				ft_dprintf(2, "pipex: %s: command not found\n", cmds[i]->argv[0]);
			clean_pipex(cmds, size);
			exit(EXIT_FAILURE);
		}
		close_fds(cmds[i]);
		i++;
	}
	while(wait(NULL) != -1 || errno != ECHILD);
}

