/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:44:49 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/12 13:54:28 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	w_cnt(t_lexer *lexed)
{
	int	count;

	count = 0;
	while (lexed && lexed->type != PIPES)
	{
		if (lexed->type == WORDS)
			count++;
		lexed = lexed->next;
	}
	return (count);
}

static t_lexer	*ft_newnode(void *content)
{
	t_lexer	*node;

	node = ft_calloc(sizeof(t_lexer), 1);
	if (!node)
		return (NULL);
	node->content = ft_strdup(content);
	node->next = NULL;
	return (node);
}

static int	get_type(char *arg, int delim)
{
	int	i;

	i = 0;
	if ((arg[i] == '<' || arg[i] == '>') && delim <= PIPES)
	{
		if (arg[i + 1] == arg[i] && arg[i] == '<')
			return (LIM);
		else if (arg[i + 1] == arg[i] && arg[i] == '>')
			return (APP);
		else if (arg[i] == '<')
			return (IN);
		else
			return (OUT);
	}
	else if (arg[i] == '|' && delim < PIPES)
		return (PIPES);
	else if (delim > PIPES)
	{
		if (!check_filename(arg))
			return (-1);
		else
			return (FILENAME);
	}
	else
		return (WORDS);
}

static int	fill_lexer(t_lexer *new, t_lexer **ret_lex,
		char **args, t_minishell *sh)
{
	int	i;
	int	type;

	i = 0;
	type = 0;
	while (args && args[i])
	{
		new = ft_newnode(args[i]);
		if (!new)
			error_parsing(*ret_lex, sh, sh->nb_cmds);
		type = get_type(args[i], type);
		new->type = type;
		if (new->type == -1)
		{
			ft_lexclear(&new, del);
			ft_lexclear(ret_lex, del);
			return (0);
		}
		ft_lex_addback(ret_lex, new);
		i++;
	}
	return (1);
}

t_lexer	*lex(char *argv, t_minishell *sh)
{
	t_lexer	*new;
	t_lexer	*ret_lex;
	char	**args;

	ret_lex = NULL;
	new = NULL;
	args = ft_split_outquote(argv);
	if (!args)
		error_parsing(NULL, sh, sh->nb_cmds);
	if (!fill_lexer(new, &ret_lex, args, sh))
	{
		ft_free_strs(args);
		return (NULL);
	}
	ft_free_strs(args);
	return (ret_lex);
}
