/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:44:05 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/10 13:47:53 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_env_size(char **str);

void	get_envp(char **envp, t_minishell *shell)
{
	int		i;
	char	**env;

	i = 0;
	if (!*envp)
	{
		shell->envp = NULL;
		return ;
	}
	env = ft_calloc(sizeof(char *), get_env_size(envp) + 1);
	if (!env)
		error_exit(shell, shell->nb_cmds);
	while (envp[i])
	{
		env[i] = ft_strdup(envp[i]);
		if (!env[i])
			error_exit(shell, shell->nb_cmds);
		i++;
	}
	env[i] = NULL;
	shell->envp = env;
}

static int	get_env_size(char **str)
{
	int	i;

	if (!str || !*str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
