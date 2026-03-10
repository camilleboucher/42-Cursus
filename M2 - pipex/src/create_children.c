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
#include "pipex.h"
#include "create_children.h"
#include "fds.h"

static bool	skip_iofiles_or_get_fds(t_cmd **cmds, int size,
									int *i, t_io_data *io);
static void	exit_child(t_cmd **cmds, int size, int i);
static int	get_exit_code(int wstatus);

int	make_love(t_cmd **cmds, int size, char *envp[], t_io_data *io)
{
	int	i;
	int	wstatus;

	i = 0;
	while (i < size)
	{
		if (skip_iofiles_or_get_fds(cmds, size, &i, io))
			continue ;
		cmds[i]->pid = fork();
		if (cmds[i]->pid == -1)
			error_exit(cmds, size);
		if (!cmds[i]->pid)
		{
			duplicate_fds(cmds[i]);
			close_all(cmds, size);
			if (execve(cmds[i]->path, cmds[i]->argv, envp) == -1)
				exit_child(cmds, size, i);//TODO: non necessaire plus tard car error access plus tard
		}
close_all(cmds, size);

		if (i)
		{
			if (cmds[i - 1]->fds[OUT] != -1)
				close(cmds[i - 1]->fds[OUT]);
			cmds[i - 1]->fds[OUT] = -1;
			if (cmds[i]->fds[IN] != -1)
				close(cmds[i]->fds[IN]);
			cmds[i]->fds[IN] = -1;
		}
		if (i == size -1)
			close_fds(&cmds[i]->fds);




		i++;
	}
	//TODO: fork pour afficher les erreurs access
	wait_children(cmds, size, io, &wstatus);
	//TODO: wait pour le fork des erreurs
	return (get_exit_code(wstatus));
}

static bool	skip_iofiles_or_get_fds(t_cmd **cmds, int size,
									int *i, t_io_data *io)
{
	if (*i == 0)
	{
		if (io->skip_infile)
		{
			(*i)++;
			return (true);
		}
	}
	else if (*i == size - 1)
	{
		if (io->skip_outfile)
		{
			(*i)++;
			return (true);
		}
	}
	else if (cmds[*i]->pid == -1)
		get_fds(cmds, size, *i, io);
	return (false);
}

static void	exit_child(t_cmd **cmds, int size, int i)
{
	int	exit_code;

	exit_code = EXIT_FAILURE;
	if (access(cmds[i]->path, F_OK) == -1)
	{
		if (!cmds[i]->argv[0])
			ft_dprintf(2, "pipex: : command not found\n");
		else
			ft_dprintf(2, "pipex: %s: command not found\n", cmds[i]->argv[0]);
		exit_code = 127;
	}
	else if (access(cmds[i]->path, X_OK) == -1)
	{
		ft_dprintf(2, "pipex: %s: permission denied\n", cmds[i]->argv[0]);
		exit_code = 126;
	}
	clean_pipex(cmds, size);
	exit(exit_code);
}

void	wait_children(t_cmd **cmds, int size, t_io_data *io, int *wstatus)
{
	int		i;

	i = 0;
	*wstatus = EXIT_SUCCESS;
	while (i < size)
	{
		if (skip_iofiles_or_get_fds(cmds, size, &i, io))
			continue ;
		if (cmds[i]->pid != -1)
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
