/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_children.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/11 23:10:04 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "ft_stdio.h"
#include "access_errors.h"
#include "pipex.h"
#include "create_children.h"
#include "create_children_utils.h"
#include "fds.h"

static bool	skip_iofiles_or_get_fds(t_cmd **cmds, int size,
				int *i, t_io_data *io);
static bool	make_child_logic(t_cmd **cmds, int size, int i, char *envp[]);
static void	exit_child(t_cmd **cmds, int size);

int	make_love(t_cmd **cmds, int size, char *envp[], t_io_data *io)
{
	int	i;
	int	wstatus;
	int	exit_code;

	i = 0;
	while (i < size)
	{
		if (skip_iofiles_or_get_fds(cmds, size, &i, io))
			continue ;
		if (!make_child_logic(cmds, size, i, envp))
		{
			ft_dprintf(2, "pipex: fork: Resource temporarily unavailable\n");
			wait_children(cmds, size, io, &wstatus);
			error_exit(cmds, size);
		}
		close_pipe(cmds, size, i);
		i++;
	}
	exit_code = access_and_wait_children(cmds, size, io);
	return (exit_code);
}

static bool	skip_iofiles_or_get_fds(t_cmd **cmds, int size,
									int *i, t_io_data *io)
{
	if (*i == size - 1)
	{
		if (io->skip_outfile)
		{
			(*i)++;
			return (true);
		}
		else
			return (false);
	}
	else
	{
		if (cmds[*i]->pid == -1)
			get_fds(cmds, size, *i, io);
		if (*i == 0)
		{
			if (io->skip_infile)
			{
				(*i)++;
				return (true);
			}
		}
	}
	return (false);
}

static bool	make_child_logic(t_cmd **cmds, int size, int i, char *envp[])
{
	cmds[i]->pid = fork();
	if (cmds[i]->pid == -1)
		return (false);
	if (!cmds[i]->pid)
	{
		duplicate_fds(cmds[i]);
		close_all(cmds, size);
		if (!cmds[i]->argv[0])
		{
			if (execve(cmds[i]->path, (char *[]){"", NULL}, envp) == -1)
				exit_child(cmds, size);
		}
		if (execve(cmds[i]->path, cmds[i]->argv, envp) == -1)
			exit_child(cmds, size);
	}
	return (true);
}

static void	exit_child(t_cmd **cmds, int size)
{
	clean_pipex(cmds, size);
	exit(EXIT_FAILURE);
}

void	wait_children(t_cmd **cmds, int size, t_io_data *io, int *wstatus)
{
	int		i;

	i = 0;
	*wstatus = EXIT_SUCCESS;
	while (i < size)
	{
		if (skip_iofiles(size, &i, io))
			continue ;
		if (cmds[i]->pid != -1)
			waitpid(cmds[i]->pid, wstatus, 0);
		i++;
	}
}
