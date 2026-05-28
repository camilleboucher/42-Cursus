/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:49:21 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/12 13:24:20 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_quoted(char *content, int i)
{
	while (content[i])
	{
		if (content[i] == '\'')
			return (true);
		else if (content[i] == '\"')
			return (true);
		i++;
	}
	return (false);
}

char	**process_word(char *content, t_minishell *parse)
{
	char	*expanded;
	char	*trim;
	char	**ret;
	bool	is_quote;

	is_quote = is_quoted(content, 0);
	expanded = expand(content, parse);
	trim = trim_quotes(expanded);
	if (!trim)
		return (NULL);
	free(expanded);
	if (is_quote == false)
		ret = ft_split_outquote(trim);
	else
	{
		ret = ft_calloc(2, sizeof(char *));
		if (!ret)
			return (NULL);
		ret[0] = ft_strdup(trim);
	}
	if (!ret)
		return (NULL);
	free(trim);
	return (ret);
}

t_lexer	*process_io(t_minishell *parse, t_lexer *lex, int cmd_i)
{
	if (!fill_io(parse, lex, cmd_i))
		return (NULL);
	return (lex->next);
}

t_lexer	*fill_cmds_words(t_minishell *parse, t_lexer *lex, int cmd_i)
{
	char	**words;
	int		k;

	while (lex && lex->type == WORDS)
	{
		k = 0;
		words = process_word(lex->content, parse);
		if (!words)
			error_parsing(lex, parse, parse->nb_cmds);
		while (words && words[k])
		{
			fill_argv(parse, parse->cmds[cmd_i], words[k]);
			k++;
		}
		ft_free_strs(words);
		lex = lex->next;
	}
	return (lex);
}
