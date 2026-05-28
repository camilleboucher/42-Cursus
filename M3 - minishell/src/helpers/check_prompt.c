/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 10:33:30 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/10 14:10:42 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	check_for_open_quotes(char *str)
{
	int		i;
	bool	sq;
	bool	dq;

	i = 0;
	sq = false;
	dq = false;
	while (str[i])
	{
		if (str[i] == '\'' && !dq)
			sq = !sq;
		else if (str[i] == '\"' && !sq)
			dq = !dq;
		i++;
	}
	return (sq + dq);
}

bool	is_in_quotes(char *str, int pos)
{
	int		i;
	bool	sq;
	bool	dq;

	dq = false;
	sq = false;
	i = 0;
	while (i < pos)
	{
		if (str[i] == '\'' && !dq)
			sq = !sq;
		else if (str[i] == '\"' && !sq)
			dq = !dq;
		i++;
	}
	return (sq + dq);
}

int	check_for_specials(char *prompt, t_minishell *sh)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		if ((prompt[i] == ';' || prompt[i] == '\\')
			&& is_in_quotes(prompt, i) == false)
		{
			printf("NavidShell: We're sorry, we don't support '%c' for now.\n",
				prompt[i]);
			sh->exit_c = 2;
			return (1);
		}
		i++;
	}
	if (check_for_open_quotes(prompt))
	{
		printf("NavidShell: You left a quote open, bruh.\n");
		sh->exit_c = 2;
		return (1);
	}
	return (0);
}

static bool	is_valid_side(char *prompt, int i, int dir)
{
	i += dir;
	if (i < 0)
		return (false);
	while (i >= 0 && prompt[i] == ' ')
		i += dir;
	if (i < 0)
		return (false);
	return (prompt[i] && prompt[i] != '|');
}

bool	check_pipe_syntax(char *prompt, t_minishell *sh)
{
	int	i;

	i = 0;
	while (prompt && prompt[i])
	{
		if (prompt[i] == '|')
		{
			if ((!is_valid_side(prompt, i, -1) || !is_valid_side(prompt, i, 1))
				&& !is_in_quotes(prompt, i))
			{
				ft_dprintf(2, "Syntax Error : | is an invalid token\n");
				sh->exit_c = 2;
				return (false);
			}
		}
		i++;
	}
	return (true);
}
