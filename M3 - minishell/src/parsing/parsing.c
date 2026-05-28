/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:12:38 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/11 15:24:11 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	cmd->path = NULL;
	cmd->pid = -1;
	cmd->fds[0] = -1;
	cmd->fds[1] = -1;
	cmd->built_in = NULL;
	cmd->argv = NULL;
}

static unsigned int	count_pipes(t_lexer *lexed, t_minishell *sh)
{
	int	count;

	count = 0;
	if (!lexed)
		error_parsing(lexed, sh, 0);
	while (lexed)
	{
		if (lexed->type == PIPES)
			count++;
		lexed = lexed->next;
	}
	return (count);
}

static void	fill_cmds(t_minishell *parse, t_lexer *lex)
{
	int	i;

	i = 0;
	while (lex)
	{
		parse->cmds[i]->argv = NULL;
		while (lex && lex->type != PIPES)
		{
			if (lex->type == WORDS)
				lex = fill_cmds_words(parse, lex, i);
			else if (lex->type > PIPES)
				lex = process_io(parse, lex, i);
			else
				lex = lex->next;
		}
		if (lex && lex->type == PIPES)
			lex = lex->next;
		if (!lex)
			break ;
		i++;
	}
}

void	init_parse(t_minishell *parsing, t_lexer *lexed)
{
	int	i;

	i = -1;
	parsing->nb_cmds = count_pipes(lexed, parsing) + 1;
	parsing->cmds = ft_calloc(parsing->nb_cmds, sizeof(t_cmd *));
	parsing->ios = ft_calloc(parsing->nb_cmds, sizeof(t_io *));
	parsing->parse_err = false;
	if (!parsing->cmds || !parsing->ios)
		error_parsing(lexed, parsing, parsing->nb_cmds);
	while (++i < (int) parsing->nb_cmds)
	{
		parsing->cmds[i] = ft_calloc(1, sizeof(t_cmd));
		parsing->ios[i] = ft_calloc(1, sizeof(t_io));
		if (!parsing->cmds[i] || !parsing->ios[i])
			error_parsing(lexed, parsing, parsing->nb_cmds);
		init_cmd(parsing->cmds[i]);
	}
}

int	parse(char *line, t_minishell *parsing)
{
	t_lexer	*lexed;
	char	*new_line;

	new_line = add_spaces_around_ops(line, parsing);
	lexed = lex(new_line, parsing);
	if (!lexed)
	{
		free(new_line);
		parsing->exit_c = 2;
		return (1);
	}
	init_parse(parsing, lexed);
	fill_cmds(parsing, lexed);
	ft_lexclear(&lexed, del);
	if (parsing->parse_err == true)
	{
		free(new_line);
		cleaning_for_next_prompt(parsing, parsing->nb_cmds);
		return (1);
	}
	free(new_line);
	return (0);
}
