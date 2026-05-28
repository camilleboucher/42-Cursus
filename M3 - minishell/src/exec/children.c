/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:48:49 by Camille           #+#    #+#             */
/*   Updated: 2026/04/18 15:46:27 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_built_in(t_minishell *sh, t_cmd *cmd, int nb_cmds);
static int	print_error(char *path, char *bin);
static void	error_exit_child(t_minishell *sh, int nb_cmds, int exit_c);

void	make_child(t_minishell *sh, t_cmd *cmd, char **env_path)
{
	int	wstatus;

	cmd->pid = fork();
	if (!cmd->pid)
	{
		duplicate_fds(cmd);
		close_all_fds(sh->cmds, sh->nb_cmds);
		ft_free_strs(env_path);
		reset_signals();
		if (cmd->built_in)
			exit(exec_built_in(sh, cmd, sh->nb_cmds));
		else if (execve(cmd->path, cmd->argv, sh->envp) == -1)
		{
			wstatus = print_error(cmd->path, cmd->argv[0]);
			error_exit_child(sh, sh->nb_cmds, wstatus);
		}
	}
	else if (cmd->pid == -1)
	{
		wait_children(sh->cmds, sh->nb_cmds, &wstatus);
		error_exit(sh, sh->nb_cmds);
	}
}

void	wait_children(t_cmd **cmds, int nb_cmds, int *wstatus)
{
	int	i;

	i = 0;
	while (i < nb_cmds)
	{
		if (cmds[i]->pid != -1)
			waitpid(cmds[i]->pid, wstatus, 0);
		i++;
	}
}

static int	exec_built_in(t_minishell *sh, t_cmd *cmd, int nb_cmds)
{
	int	exit_code;

	exit_code = cmd->built_in(sh, cmd);
	cleaning(sh, nb_cmds);
	return (exit_code);
}

static int	print_error(char *path, char *bin)
{
	struct stat	sb;

	if (!*bin)
	{
		ft_dprintf(2, "minishell: command not found\n");
		return (EXIT_NOTFOUND);
	}
	if (stat(path, &sb) == -1)
	{
		if (ft_strchr(bin, '/'))
			ft_dprintf(2, "minishell: %s: No such file or directory\n", bin);
		else
			ft_dprintf(2, "minishell: %s: command not found\n", bin);
		return (EXIT_NOTFOUND);
	}
	else
	{
		if (S_ISDIR(sb.st_mode))
			ft_dprintf(2, "minishell: %s: Is a directory\n", bin);
		else if (access(path, X_OK) == -1)
			ft_dprintf(2, "minishell: %s: permission denied\n", bin);
		else
			ft_dprintf(2, "minishell: %s: Not an handled file\n", bin);
		return (EXIT_NOTEXECUTABLE);
	}
}

static void	error_exit_child(t_minishell *sh, int nb_cmds, int exit_c)
{
	cleaning(sh, nb_cmds);
	exit(exit_c);
}
