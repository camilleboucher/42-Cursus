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

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ft_stdio.h"
#include "get_next_line.h"
#include "pipex.h"
#include "fds.h"

static int	skip_iofiles_or_not(t_cmd **cmds, int *i, int size);
static void	exit_child(t_cmd **cmds, int size, int i);
static void	wait_children(t_cmd **cmds, int nb_children, int *wstatus);
static int	get_exit_code(int wstatus);

int	make_love(t_cmd **cmds, int size, char *envp[])
{
	int	i;
	int	nb_children;
	int	wstatus;

	nb_children = skip_iofiles_or_not(cmds, &i, size);
	while (i < nb_children)
	{
		cmds[i]->pid = fork();
		if (cmds[i]->pid == -1)
			error_exit(cmds, size);
		if (!cmds[i]->pid)
		{
			duplicate_fds(cmds[i]);
			close_all(cmds, size);
			if (execve(cmds[i]->path, cmds[i]->argv, envp) == -1)
				exit_child(cmds, size, i);
		}
		close_fds(&cmds[i]->fds);
		if (cmds[i]->fds_errmsg[OUT] != -1)
			close(cmds[i]->fds_errmsg[OUT]);
		cmds[i]->fds_errmsg[OUT] = -1;
		i++;
	}
	wait_children(cmds, nb_children, &wstatus);
	return (get_exit_code(wstatus));
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
	int	exit_code;

	if (access(cmds[i]->path, F_OK) == -1)
	{
		if (!cmds[i]->argv[0])
			ft_dprintf(2, "pipex: : command not found\n");
		else
			ft_dprintf(2, "pipex: %s: command not found\n", cmds[i]->argv[0]);
		exit_code = 127;
	}
	else
	{
		if (access(cmds[i]->path, X_OK) == -1)
			ft_dprintf(2, "pipex: %s: permission denied\n", cmds[i]->argv[0]);
		exit_code = 126;
	}
	clean_pipex(cmds, size);
	close(STDIN_FILENO);//TODO:a voir a lecole
	close(STDOUT_FILENO);
	close(STDERR_FILENO);//TODO:jusquici
	exit(exit_code);
}

static void	wait_children(t_cmd **cmds, int nb_children, int *wstatus)
{
	int		i;
	char	*err_line;

	i = 0;
	if (cmds[0]->fds[IN] == -1)
		i = 1;
	while (i < nb_children)
	{
		err_line = get_next_line(cmds[i]->fds_errmsg[IN]);
		ft_dprintf(2, err_line);
		free(err_line);
		close_fds(&cmds[i]->fds_errmsg);
		i++;
	}
	i = 0;
	if (cmds[0]->fds[IN] == -1)
		i = 1;
	*wstatus = EXIT_SUCCESS;
	while (i < nb_children)
	{
		waitpid(cmds[i]->pid, wstatus, 0);
		i++;
	}
}

static int	get_exit_code(int wstatus)
{
	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	else if (WIFSIGNALED(wstatus))
		return (WTERMSIG(wstatus) + 128);
	return (EXIT_FAILURE);
}
