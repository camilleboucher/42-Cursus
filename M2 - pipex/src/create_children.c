/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_children.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/07 11:48:25 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "ft_stdio.h"
#include "pipex.h"
#include "fds.h"

static int	skip_iofiles_or_not(t_cmd **cmds, int *i, int size);
static void	exit_child(t_cmd **cmds, int size, int i);

void	make_love(t_cmd **cmds, int size, char *envp[])
{
	int	i;
	int	nb_children;

	nb_children = skip_iofiles_or_not(cmds, &i, size);
	while (i < nb_children)
	{
		cmds[i]->pid = fork();
		if (cmds[i]->pid == -1)
			error_exit(cmds, size);
		if (!cmds[i]->pid)
		{
			if (cmds[i]->fds[IN] != -1)
				dup2(cmds[i]->fds[IN], STDIN_FILENO);
			if (cmds[i]->fds[OUT] != -1)
				dup2(cmds[i]->fds[OUT], STDOUT_FILENO);
			close_all_fds(cmds, size);
			if (execve(cmds[i]->path, cmds[i]->argv, envp) == -1)
				exit_child(cmds, size, i);
		}
		close_fds(cmds[i]);
		i++;
	}
	while(wait(NULL) != -1 || errno != ECHILD);
}

static int	skip_iofiles_or_not(t_cmd **cmds, int *i, int size)
{
	int	nb_children;

	*i = 0;
	nb_children = size;
	if (cmds[0]->fds[IN] == -1)
		*i = 1;
	if (cmds[size - 1]->fds[OUT] == -1)
		nb_children--;
	return (nb_children);
}

static void	exit_child(t_cmd **cmds, int size, int i)
{
	if (access(cmds[i]->path, F_OK) == -1)
	{
		if (!cmds[i]->argv[0])
			ft_dprintf(2, "pipex: command not found: \n");
		else
			ft_dprintf(2, "pipex: command not found: %s\n", cmds[i]->argv[0]);
	}
	else
	{
		if (access(cmds[i]->path, X_OK) == -1)
			ft_dprintf(2, "pipex: permission denied: %s\n", cmds[i]->argv[0]);
	}
	clean_pipex(cmds, size);
	exit(EXIT_FAILURE);
}
