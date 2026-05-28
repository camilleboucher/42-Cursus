/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 14:34:46 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/10 15:04:17 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	has_closing_sq(char *str, int pos)
{
	int	i;

	i = pos + 1;
	while (str[i])
	{
		if (str[i] == '\'')
			return (true);
		i++;
	}
	return (false);
}

static bool	has_closing_dq(char *str, int pos)
{
	int	i;

	i = pos + 1;
	while (str[i])
	{
		if (str[i] == '\"')
			return (true);
		i++;
	}
	return (false);
}

static void	check_and_fill(char *str, char *trim, int i, int j)
{
	if (str[i] == '\x01')
		trim[j++] = '\"';
	else if (str[i] == '\x02')
		trim[j++] = '\'';
	else
		trim[j++] = str[i];
}

static void	fill_trim(char *str, char *trim, int i, int j)
{
	bool	in_sq;
	bool	in_dq;

	in_sq = false;
	in_dq = false;
	while (str && str[i])
	{
		if (str[i] == '\'' && !in_dq && (in_sq || has_closing_sq(str, i)))
		{
			in_sq = !in_sq;
			i++;
		}
		else if (str[i] == '"' && !in_sq && (in_dq || has_closing_dq(str, i)))
		{
			in_dq = !in_dq;
			i++;
		}
		else
		{
			check_and_fill(str, trim, i, j);
			i++;
			j++;
		}
	}
}

char	*trim_quotes(char *str)
{
	char	*trim;

	if (!str)
		return (NULL);
	trim = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!trim)
		return (NULL);
	fill_trim(str, trim, 0, 0);
	return (trim);
}
