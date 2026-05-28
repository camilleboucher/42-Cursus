/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:40:55 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/04 16:13:08 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_hidden(char *var)
{
	int	i;

	i = 0;
	while (var && var[i])
	{
		if (var[i] == '=')
			return (false);
		i++;
	}
	return (true);
}

int	ft_env(t_minishell *sh, t_cmd *cmd)
{
	int	i;

	(void) cmd;
	i = 0;
	if (get_argc(cmd->argv) > 1)
	{
		ft_dprintf(2, "NavidShell: Syntax Error, too many arguments\n");
		return (2);
	}
	if (!sh->envp)
		return (EXIT_SUCCESS);
	while (sh->envp && sh->envp[i])
	{
		if (is_hidden(sh->envp[i]) == false)
			printf("%s\n", sh->envp[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
