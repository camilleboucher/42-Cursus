/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:07:53 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/12 14:21:00 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_quotes(char c, bool *sq, bool *dq)
{
	if (c == '\'' && !*dq)
		*sq = !*sq;
	else if (c == '"' && !*sq)
		*dq = !*dq;
}

static size_t	strcount(const char *str)
{
	size_t	i;
	size_t	count;
	bool	in_word;
	bool	is_sq;
	bool	is_dq;

	i = 0;
	count = 0;
	in_word = false;
	is_sq = false;
	is_dq = false;
	while (str[i])
	{
		check_quotes(str[i], &is_sq, &is_dq);
		if (!is_wspace(str[i]) && !is_sq && !is_dq)
		{
			if (!in_word)
				count++;
			in_word = true;
		}
		else if (!is_sq && !is_dq)
			in_word = false;
		i++;
	}
	return (count + 1);
}

static size_t	to_next_c(const char *str)
{
	size_t	i;
	bool	is_sq;
	bool	is_dq;

	is_dq = false;
	is_sq = false;
	i = 0;
	while (str[i] && (!is_wspace(str[i]) || is_sq || is_dq))
	{
		check_quotes(str[i], &is_sq, &is_dq);
		i++;
	}
	return (i);
}

static char	**fill_tab(char **tab, char const *s)
{
	int	i;
	int	next_char;

	i = 0;
	while (*s)
	{
		if (!is_wspace(*s))
		{
			next_char = to_next_c(s);
			tab[i] = ft_substr(s, 0, next_char);
			if (!tab[i])
			{
				ft_free_strs(tab);
				return (NULL);
			}
			i++;
			s += next_char;
		}
		else
			s++;
	}
	return (tab);
}

char	**ft_split_outquote(char const *s)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = ft_calloc((strcount(s) + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	tab = fill_tab(tab, s);
	return (tab);
}
