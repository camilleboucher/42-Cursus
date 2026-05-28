/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 16:07:59 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/16 14:22:52 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expand_file(char *str, t_minishell *sh, t_lexer *lex, t_io *io)
{
	char	*trim;
	char	*expanded;

	if (lex->type == LIM)
	{
		if (!ft_strchr(str, '\"') && !ft_strchr(str, '\''))
			io->expand_heredoc = true;
		trim = trim_quotes(str);
		if (!trim)
			error_parsing(lex, sh, sh->nb_cmds);
		return (trim);
	}
	expanded = expand(str, sh);
	trim = trim_quotes(expanded);
	if (!trim)
		error_parsing(lex, sh, sh->nb_cmds);
	free(expanded);
	return (trim);
}

static t_io	*ft_newnode(t_minishell *sh, t_lexer *lex)
{
	t_io	*node;

	node = ft_calloc(sizeof(t_io), 1);
	if (!node)
		error_parsing(lex, sh, sh->nb_cmds);
	node->next = NULL;
	return (node);
}

static t_io	*add_io(t_lexer *lexed, t_minishell *sh)
{
	t_io	*io;

	io = ft_newnode(sh, lexed);
	if (lexed->type == IN && lexed->next != NULL)
	{
		io->infile = expand_file(lexed->next->content, sh, lexed, io);
		io->is_lim = false;
	}
	else if (lexed->type == OUT && lexed->next != NULL)
	{
		io->outfile = expand_file(lexed->next->content, sh, lexed, io);
		io->outfile_flags = O_CREAT | O_TRUNC | O_WRONLY;
	}
	else if (lexed->type == LIM && lexed->next != NULL)
	{
		io->infile = expand_file(lexed->next->content, sh, lexed, io);
		io->is_lim = true;
	}
	else if (lexed->type == APP && lexed->next != NULL)
	{
		io->outfile = expand_file(lexed->next->content, sh, lexed, io);
		io->outfile_flags = O_CREAT | O_APPEND | O_WRONLY;
	}
	return (io);
}

static void	replace_first_io(t_minishell *sh, t_lexer *lexed, int i)
{
	t_io	*tmp;

	tmp = add_io(lexed, sh);
	if (!tmp)
		return ;
	free(sh->ios[i]);
	sh->ios[i] = tmp;
}

t_lexer	*fill_io(t_minishell *shell, t_lexer *lexed, int i)
{
	t_io	*content;
	t_io	*last;

	if (!lexed->next)
	{
		ft_dprintf(2, "Error: Filename cannot be empty.\n");
		shell->exit_c = 2;
		shell->parse_err = true;
		return (NULL);
	}
	if (!shell->ios[i]->infile && !shell->ios[i]->outfile)
		replace_first_io(shell, lexed, i);
	else
	{
		last = ft_iolast(shell->ios[i]);
		if (!last)
			return (NULL);
		content = add_io(lexed, shell);
		last->next = content;
	}
	return (lexed->next);
}
