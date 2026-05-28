/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:19:39 by Camille           #+#    #+#             */
/*   Updated: 2026/05/12 14:25:45 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	can_execute_cd(char **argv, t_minishell *sh);
static bool	handling_home_dir(int argc, t_minishell *sh);
static bool	handling_tilde(char *home_path, char *first_home_dir_path);
static bool	update_envpwd_and_old(char *oldpwd_path, t_minishell *sh);

int	ft_cd(t_minishell *sh, t_cmd *cmd)
{
	char	*oldpwd_path;
	char	*newpwd_path;

	if (sh->nb_cmds > 1 && handle_pipes_for_cd(sh, sh->nb_cmds, cmd->argv))
		return (EXIT_FAILURE);
	oldpwd_path = getcwd(NULL, 0);
	if (!can_execute_cd(cmd->argv, sh))
	{
		free(oldpwd_path);
		return (EXIT_FAILURE);
	}
	if (!update_envpwd_and_old(oldpwd_path, sh))
		error_exit(sh, sh->nb_cmds);
	newpwd_path = getcwd(NULL, 0);
	if (!newpwd_path)
	{
		ft_dprintf(2,
			"minishell: cd: error retrieving current directory: getcwd: ");
		ft_dprintf(2,
			"cannot access parent directories: No such file or directory");
		ft_dprintf(2, "\n");
	}
	else
		free(newpwd_path);
	return (EXIT_SUCCESS);
}

static bool	can_execute_cd(char **argv, t_minishell *sh)
{
	int	argc;

	argc = get_argc(argv);
	if (argc > 2)
	{
		ft_dprintf(2, "minishell: cd: too many arguments\n");
		return (false);
	}
	if (argc == 1 || (ft_strlen(argv[1]) == 1 && argv[1][0] == '~'))
		return (handling_home_dir(argc, sh));
	else
	{
		if (chdir(argv[1]) == -1)
		{
			ft_dprintf(2, "minishell: cd: %s: %s\n", argv[1], strerror(errno));
			return (false);
		}
	}
	return (true);
}

static bool	handling_home_dir(int argc, t_minishell *sh)
{
	char	*home_path;

	home_path = ft_getenv("HOME", (const char **)sh->envp);
	if (argc == 1 && !home_path)
	{
		ft_dprintf(2, "minishell: cd: HOME not set\n");
		return (false);
	}
	if (argc == 1)
	{
		if (!*home_path)
			return (true);
		if (chdir(home_path) == -1)
		{
			ft_dprintf(2,
				"minishell: cd: %s: %s\n", home_path, strerror(errno));
			return (false);
		}
	}
	else
		return (handling_tilde(home_path, sh->first_home_dir_path));
	return (true);
}

static bool	handling_tilde(char *home_path, char *first_home_dir_path)
{
	char	*home_path_to_use;

	if (home_path && !*home_path)
		return (true);
	if (home_path)
		home_path_to_use = home_path;
	else
	{
		home_path_to_use = first_home_dir_path;
		if (!first_home_dir_path)
			return (true);
	}
	if (chdir(home_path_to_use) == -1)
	{
		ft_dprintf(2, "minishell: cd: %s: %s\n", home_path, strerror(errno));
		return (false);
	}
	return (true);
}

static bool	update_envpwd_and_old(char *oldpwd_path, t_minishell *sh)
{
	char	*pwd_path;
	char	*newpwd_path;

	if (!oldpwd_path)
		oldpwd_path = ft_strdup(sh->cwd);
	pwd_path = oldpwd_path;
	oldpwd_path = ft_strjoin("OLDPWD=", oldpwd_path);
	free(pwd_path);
	if (!oldpwd_path)
		return (false);
	ft_set_env(oldpwd_path, sh);
	free(oldpwd_path);
	pwd_path = getcwd(NULL, 0);
	if (!pwd_path)
		pwd_path = ft_strdup(sh->cwd);
	newpwd_path = ft_strjoin("PWD=", pwd_path);
	free(pwd_path);
	if (!newpwd_path)
		return (false);
	ft_set_env(newpwd_path, sh);
	free(newpwd_path);
	return (true);
}
