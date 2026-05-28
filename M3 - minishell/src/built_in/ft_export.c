/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:40:57 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/09 15:21:01 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_correct_varname(char *var)
{
	int	i;

	i = 0;
	if ((ft_isdigit(var[0]) || !ft_isalpha(var[0]))
		&& var[0] != '_')
		return (false);
	while (var[i] && var[i] != '=')
	{
		if (!ft_isalnum(var[i]) && var[i] != '_'
			&& !(var[i] == '+' && var[i + 1] == '='))
			return (false);
		i++;
	}
	return (true);
}

static void	print_with_quotes(char *str)
{
	int	i;

	i = -1;
	printf("declare -x ");
	while (str && str[++i] != '=')
		printf("%c", str[i]);
	printf("%c\"", str[i]);
	while (str && str[++i])
		printf("%c", str[i]);
	printf("\"\n");
}

static int	check_for_args(t_minishell *sh, t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->argv[0] && !cmd->argv[1])
	{
		while (sh->envp && sh->envp[i])
		{
			if (ft_strchr(sh->envp[i], '='))
				print_with_quotes(sh->envp[i]);
			else
				printf("declare -x %s\n", sh->envp[i]);
			i++;
		}
		return (1);
	}
	return (0);
}

static bool	check_append(char *var)
{
	int	i;

	i = 0;
	while (var && var[i] && var[i] != '=')
	{
		if (var[i] == '+' && var[i + 1] == '=')
			return (true);
		i++;
	}
	return (false);
}

int	ft_export(t_minishell *sh, t_cmd *cmd)
{
	int		i;
	bool	error;

	error = false;
	if (sh->nb_cmds > 1 || check_for_args(sh, cmd))
		return (EXIT_SUCCESS);
	i = 0;
	while (cmd->argv[++i])
	{
		if (is_correct_varname(cmd->argv[i]) == false)
		{
			ft_dprintf(2,
				"export: Error. \"%s\"'s not a valid ID.\n", cmd->argv[i]);
			error = true;
		}
		else if (check_append(cmd->argv[i]))
			handle_append(cmd->argv[i], sh);
		else
			ft_set_env(cmd->argv[i], sh);
	}
	return ((int)error);
}
