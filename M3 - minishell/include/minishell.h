/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:12:57 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/07 16:35:52 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "ft_list.h"
# include "ft_stdio.h"
# include "ft_stdlib.h"
# include "ft_string.h"
# include "strutils.h"
# include "ft_ctype.h"
# include "structs.h"
# include "signals.h"
# include "parsing.h"
# include "exec.h"
# include "cleaning.h"
# include "builts_in.h"

/* FILL_IO_C */
t_lexer	*fill_io(t_minishell *shell, t_lexer *lexed, int i);

/* FILL_IO_C */
t_io	*ft_iolast(t_io *lst);
t_io	*ft_iolast(t_io *lst);

/* GET_ENVP_C */
void	get_envp(char **envp, t_minishell *shell);

/* CHECK_PROMPT_C */
int		check_for_specials(char *prompt, t_minishell *sh);
bool	is_in_quotes(char *str, int pos);
bool	check_pipe_syntax(char *prompt, t_minishell *sh);

/* CHECK_ONLY_SPACES_C */
bool	check_only_spaces(char *prompt);

#endif
