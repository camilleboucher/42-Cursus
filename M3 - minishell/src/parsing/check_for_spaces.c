/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:48:44 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/11 16:45:00 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	count_spaces(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str && str[++i])
	{
		if (is_redir(str[i]) && !is_in_quotes(str, i))
		{
			if (i > 0 && str[i - 1] != ' '
				&& (str[i - 1] != str[i] || is_third_op(str, i)))
				count++;
			if (str[i + 1] && str[i + 1] != ' '
				&& (str[i + 1] != str[i] || is_double_op(str, i)))
				count++;
		}
		else if (is_pipes(str[i]) && !is_in_quotes(str, i))
		{
			if (i > 0 && str[i - 1] != ' ')
				count++;
			if (str[i + 1] && str[i + 1] != ' ')
				count++;
		}
	}
	return (count);
}

static void	add_spaces(char *line, char *new, int *i, int *j)
{
	if (is_redir(line[*i]) && !is_in_quotes(line, *i))
	{
		if (*i > 0 && line[*i - 1] != ' '
			&& (line[*i - 1] != line[*i] || is_third_op(line, *i)))
			new[(*j)++] = ' ';
		new[(*j)++] = line[*i];
		if (line[*i + 1] && line[*i + 1] != ' '
			&& (line[*i + 1] != line[*i] || is_double_op(line, *i)))
			new[(*j)++] = ' ';
	}
	else if (is_pipes(line[*i]) && !is_in_quotes(line, *i))
	{
		if (*i > 0 && line[*i - 1] != ' ')
			new[(*j)++] = ' ';
		new[(*j)++] = line[*i];
		if (line[*i + 1] && line[*i + 1] != ' ')
			new[(*j)++] = ' ';
	}
	else
		new[(*j)++] = line[*i];
	(*i)++;
}

char	*add_spaces_around_ops(char *line, t_minishell *sh)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = ft_calloc(sizeof(char *), ft_strlen(line) + count_spaces(line) + 1);
	if (!new)
		error_exit(sh, sh->nb_cmds);
	while (line && line[i])
		add_spaces(line, new, &i, &j);
	return (new);
}
