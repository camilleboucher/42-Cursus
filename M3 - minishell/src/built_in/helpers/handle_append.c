/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:37:54 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/12 15:51:22 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_varname_wout_equal(char *str)
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
	ret = ft_calloc(i + 1, sizeof(char));
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

static char	*remove_plus(char *var, t_minishell *sh)
{
	int		i;
	int		j;
	char	*new;

	new = ft_calloc(ft_strlen(var) + 1, sizeof(char));
	if (!new)
		error_exit(sh, sh->nb_cmds);
	i = 0;
	j = 0;
	while (var && var[i] != '=')
	{
		if (var[i] == '+' && var[i + 1] == '=')
		{
			i++;
			break ;
		}
		new[j++] = var[i++];
	}
	while (var && var[i])
		new[j++] = var[i++];
	return (new);
}

static void	free_all(char *new, char *name)
{
	if (new)
		free(new);
	if (name)
		free(name);
}

static void	malloc_error(t_minishell *sh, char *new, char *name)
{
	free_all(new, name);
	error_exit(sh, sh->nb_cmds);
}

void	handle_append(char *var, t_minishell *sh)
{
	char	*new_var;
	char	*varname;
	char	*env;

	new_var = remove_plus(var, sh);
	varname = get_varname_wout_equal(new_var);
	if (!varname)
		malloc_error(sh, new_var, varname);
	env = ft_getenv(varname, (const char **)sh->envp);
	if (env)
	{
		if (!append(env, new_var, varname, sh))
			malloc_error(sh, new_var, varname);
	}
	else
		ft_set_env(new_var, sh);
	free_all(new_var, varname);
}
