/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:16:55 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/12 10:49:52 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_varname(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && (ft_isalnum(str[i]) == 1 || str[i] == '_'))
		i++;
	ret = ft_calloc(i + 2, sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i] && (ft_isalnum(str[i]) == 1 || str[i] == '_'))
	{
		ret[j] = str[i];
		j++;
		i++;
	}
	ret[j] = '\0';
	return (ret);
}

static int	get_tab_size(char **str)
{
	int	i;

	if (!str || !*str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	put_into_env(char *var, char **envp, t_minishell *shell)
{
	int		i;
	char	**env;

	i = 0;
	if (!envp)
		env = ft_calloc(sizeof(char *), 2);
	else
		env = ft_calloc(sizeof(char *), get_tab_size(envp) + 2);
	if (!env)
		error_exit(shell, shell->nb_cmds);
	while (envp && envp[i])
	{
		env[i] = ft_strdup(envp[i]);
		if (!env[i])
			error_exit(shell, shell->nb_cmds);
		i++;
	}
	env[i] = ft_strdup(var);
	env[i + 1] = NULL;
	if (!env[i])
		error_exit(shell, shell->nb_cmds);
	ft_free_strs(shell->envp);
	shell->envp = env;
}

static int	get_env_index(char **env, char *var)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (!ft_strncmp(env[i], var, ft_strlen(var))
			&& (env[i][ft_strlen(var)] == '='
			|| env[i][ft_strlen(var)] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}

void	ft_set_env(char *var, t_minishell *sh)
{
	char	*name;
	int		i;

	name = get_varname(var);
	if (!name)
		error_exit(sh, sh->nb_cmds);
	if (name && !ft_strchr(var, '='))
	{
		if (get_env_index(sh->envp, name) == -1)
			put_into_env(var, sh->envp, sh);
		free(name);
		return ;
	}
	i = get_env_index(sh->envp, name);
	if (i != -1)
	{
		free(sh->envp[i]);
		sh->envp[i] = ft_strdup(var);
		if (!sh->envp[i])
			error_exit(sh, sh->nb_cmds);
	}
	else
		put_into_env(var, sh->envp, sh);
	free(name);
}
