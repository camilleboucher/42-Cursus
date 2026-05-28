/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:24:39 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/12 16:05:39 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_minishell	*init_sh(char **envp);
static char			*init_prompt(t_minishell *sh, int *i);
static char			*choose_shell_name(int *i);
static bool			read_exec(t_minishell *shell);

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*shell;
	int			i;
	int			final_exit_code;

	i = 0;
	(void) argc;
	(void) argv;
	shell = init_sh(envp);
	while (1)
	{
		shell->prompt = init_prompt(shell, &i);
		i++;
		if (!read_exec(shell))
		{
			printf("exit\n");
			break ;
		}
	}
	final_exit_code = shell->exit_c;
	cleaning(shell, 0);
	return (final_exit_code);
}

static t_minishell	*init_sh(char **envp)
{
	t_minishell	*shell;

	shell = ft_calloc(1, sizeof(t_minishell));
	if (!shell)
	{
		perror("minishell");
		exit(2);
	}
	if (envp)
		get_envp(envp, shell);
	else
		shell->envp = NULL;
	shell->first_home_dir_path = getenv("HOME");
	return (shell);
}

static char	*init_prompt(t_minishell *sh, int *i)
{
	char	*cwd;
	char	*tmp;

	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		free(sh->cwd);
		tmp = ft_strjoin(choose_shell_name(i), cwd);
		sh->cwd = cwd;
	}
	else
		tmp = ft_strjoin(choose_shell_name(i), sh->cwd);
	sh->prompt = ft_strjoin(tmp, "$ ");
	free(tmp);
	return (sh->prompt);
}

static char	*choose_shell_name(int *i)
{
	static char	*name[10] = {"NavidShell:", "Bush_Shell:", "NavidShell...?:",
		"Coquillage:", "PearlAbyssShell:", "MyShell.pk3:",
		"Fish:", "\033[0;94mHouse\033[0mShell:", "EauCalmeShell:",
		NULL};

	if (!name[*i])
		*i = 0;
	return (name[*i]);
}

static bool	read_exec(t_minishell *shell)
{
	char	*line;

	set_signals(false);
	line = readline(shell->prompt);
	ignore_signals_and_handle_sigint(shell);
	if (!line)
		return (false);
	if (line[0] != '\0')
	{
		if (check_only_spaces(line) || check_for_specials(line, shell)
			|| !check_pipe_syntax(line, shell))
		{
			free(line);
			free(shell->prompt);
			return (true);
		}
		add_history(line);
		if (!parse(line, shell))
			exec(shell, shell->nb_cmds);
	}
	free(shell->prompt);
	shell->prompt = NULL;
	free(line);
	return (true);
}
