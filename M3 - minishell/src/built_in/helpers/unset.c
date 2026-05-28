/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:48:36 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/12 14:22:57 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void	unset_and_free(char *var, t_minishell *sh)
{
	char	**new_env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_env = NULL;
	if (get_tab_size(sh->envp) > 0)
		new_env = ft_calloc(get_tab_size(sh->envp), sizeof(char *));
	if (!new_env)
		error_exit(sh, sh->nb_cmds);
	while (sh->envp && sh->envp[i])
	{
		if (ft_strncmp(var, sh->envp[i], ft_strlen(var)))
		{
			new_env[j] = ft_strdup(sh->envp[i]);
			if (!new_env[j])
				error_exit(sh, sh->nb_cmds);
			j++;
		}
		i++;
	}
	free(var);
	ft_free_strs(sh->envp);
	sh->envp = new_env;
}

static void	unset_hidden(char *var, t_minishell *sh)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	j = 0;
	new = NULL;
	if (get_tab_size(sh->envp) > 0)
		new = ft_calloc(get_tab_size(sh->envp), sizeof(char *));
	if (!new)
		error_exit(sh, sh->nb_cmds);
	while (sh->envp && sh->envp[i])
	{
		if (ft_strncmp(sh->envp[i], var, ft_strlen(sh->envp[i])))
		{
			new[j] = ft_strdup(sh->envp[i]);
			if (!new[j])
				error_exit(sh, sh->nb_cmds);
			j++;
		}
		i++;
	}
	ft_free_strs(sh->envp);
	sh->envp = new;
}

void	ft_unset_env(char *var, t_minishell *sh)
{
	char	*tmp;
	int		i;

	tmp = ft_strjoin(var, "=");
	i = 0;
	while (sh->envp && sh->envp[i])
	{
		if (!ft_strncmp(tmp, sh->envp[i], ft_strlen(tmp)))
		{
			unset_and_free(tmp, sh);
			return ;
		}
		else if (!ft_strchr(var, '=')
			&& !ft_strncmp(var, sh->envp[i], ft_strlen(sh->envp[i])))
		{
			unset_hidden(var, sh);
			free(tmp);
			return ;
		}
		i++;
	}
	free(tmp);
}
