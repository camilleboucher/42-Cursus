/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/11 23:11:33 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "access_errors.h"
#include "create_children.h"
#include "create_children_utils.h"
#include "ft_string.h"
#include "pipex.h"
#include "strutils.h"

static char	**init_errors(t_cmd **cmds, int size, t_io_data *io);
static void	get_access_errors(t_cmd **cmds, int size,
				t_io_data *io, char **errors);
static bool	malloc_access_error(t_cmd *cmd, char **errors, int *j, int errmsg);
static void	print_errors(char **errors);

int	access_and_wait_children(t_cmd **cmds, int size, t_io_data *io)
{
	char	**errors;
	int		wstatus;

	errors = init_errors(cmds, size, io);
	get_access_errors(cmds, size, io, errors);
	wait_children(cmds, size, io, &wstatus);
	print_errors(errors);
	ft_free_strs(errors);
	return (get_exit_code(wstatus));
}

static char	**init_errors(t_cmd **cmds, int size, t_io_data *io)
{
	char	**errors;
	int		wstatus;

	if (io->skip_infile)
		size--;
	if (io->skip_outfile)
		size--;
	errors = ft_calloc(sizeof(char *), size + 1);
	if (!errors)
	{
		wait_children(cmds, size, io, &wstatus);
		clean_pipex(cmds, size);
		exit(EXIT_FAILURE);
	}
	return (errors);
}

static void	get_access_errors(t_cmd **cmds, int size,
							t_io_data *io, char **errors)
{
	int		i;
	int		j;
	bool	failed_malloc;

	i = 0;
	j = 0;
	failed_malloc = false;
	while (i < size)
	{
		if (skip_iofiles(size, &i, io))
			continue ;
		if (access(cmds[i]->path, F_OK) == -1)
			failed_malloc = malloc_access_error(cmds[i], errors, &j, 1);
		else if (access(cmds[i]->path, X_OK) == -1)
			failed_malloc = malloc_access_error(cmds[i], errors, &j, 2);
		if (failed_malloc)
			return ;
		i++;
	}
}

static bool	malloc_access_error(t_cmd *cmd, char **errors, int *j, int errmsg)
{
	char	*old;

	if (errmsg == 1 && !cmd->argv[0])
		errors[*j] = ft_strdup("pipex: : command not found\n");
	if (errmsg == 2 || (errmsg == 1 && cmd->argv[0]))
		errors[*j] = ft_strjoin("pipex: ", cmd->argv[0]);
	if (errors[*j] && ((errmsg == 1 && cmd->argv[0]) || errmsg == 2))
	{
		old = errors[*j];
		if (errmsg == 1)
			errors[*j] = ft_strjoin(errors[*j], ": command not found\n");
		if (errmsg == 2)
			errors[*j] = ft_strjoin(errors[*j], ": permission denied\n");
		free(old);
	}
	if (errors[(*j)++])
		return (true);
	return (false);
}

static void	print_errors(char **errors)
{
	int	i;

	i = 0;
	while (errors[i])
	{
		ft_dprintf(2, "%s", errors[i]);
		i++;
	}
}
