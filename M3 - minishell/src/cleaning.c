/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 13:53:30 by Camille           #+#    #+#             */
/*   Updated: 2026/05/05 11:38:20 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clean_cmds(t_cmd **cmds, int nb_cmds);
static void	clean_ios(t_io **ios, int nb_cmds);

void	cleaning(t_minishell *sh, int nb_cmds)
{
	if (!sh)
		return ;
	cleaning_for_next_prompt(sh, nb_cmds);
	ft_free_strs(sh->envp);
	free(sh->cwd);
	rl_clear_history();
	free(sh);
}

void	cleaning_for_next_prompt(t_minishell *sh, int nb_cmds)
{
	clean_cmds(sh->cmds, nb_cmds);
	clean_ios(sh->ios, nb_cmds);
	free(sh->prompt);
	sh->prompt = NULL;
}

void	error_exit(t_minishell *sh, int nb_cmds)
{
	perror("minishell");
	cleaning(sh, nb_cmds);
	exit(EXIT_FAILURE);
}

static void	clean_cmds(t_cmd **cmds, int nb_cmds)
{
	int	i;

	if (!nb_cmds || !cmds)
		return ;
	i = 0;
	while (i < nb_cmds)
	{
		if (!cmds[i])
			break ;
		free(cmds[i]->path);
		ft_free_strs(cmds[i]->argv);
		close_fds(&cmds[i]->fds);
		free(cmds[i]);
		i++;
	}
	free(cmds);
}

static void	clean_ios(t_io **ios, int nb_cmds)
{
	int		i;
	t_io	*io;
	t_io	*old_io;

	if (!nb_cmds || !ios)
		return ;
	i = -1;
	while (++i < nb_cmds)
	{
		io = ios[i];
		if (!io)
			continue ;
		while (io)
		{
			old_io = io;
			free(io->infile);
			free(io->outfile);
			io = io->next;
			free(old_io);
		}
	}
	free(ios);
}
