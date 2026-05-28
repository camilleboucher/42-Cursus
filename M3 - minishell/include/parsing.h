/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 16:25:21 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/12 16:03:01 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/* LEXER_C */
t_lexer	*lex(char *argv, t_minishell *sh);
void	ft_lex_addback(t_lexer **lst, t_lexer *node);
int		w_cnt(t_lexer *lexed);

/* SPLIT_QUOTES_C*/
char	**ft_split_outquote(char const *s);

/* FT_LEXLAST_C */
t_lexer	*ft_lexlast(t_lexer *lst);

/* FT_LEXCLEAR */
void	ft_lexclear(t_lexer **lst, void (*del)(void *));
void	del(void *content);

/* TRIM_QUOTES_C */
char	*trim_quotes(char *str);

/* GET_VAR_C */
char	*get_var(char **envp, char *var);
char	*get_var_name(char *str);
int		get_size(char *str, t_minishell *shell, int i);

/* EXPAND_C */
char	*expand(char *str, t_minishell *shell);

/* IS_IN_SQ_C*/
bool	is_in_sq(char *str, int pos);

/* PARSING_C */
int		parse(char *line, t_minishell *parsing);

/* PROCESS_C */
t_lexer	*fill_cmds_words(t_minishell *parse, t_lexer *lex, int cmd_i);
t_lexer	*process_io(t_minishell *parse, t_lexer *lex, int cmd_i);
char	**process_word(char *content, t_minishell *parse);

/* FILL_IO_C */
t_lexer	*fill_io(t_minishell *shell, t_lexer *lexed, int i);

/* FILL_IO_C */
t_io	*ft_iolast(t_io *lst);
t_io	*ft_iolast(t_io *lst);

/* FILL_ARGV_C */
void	fill_argv(t_minishell *sh, t_cmd *cmd, char *word);

/* ERROR_CLEANING_C */
void	error_parsing(t_lexer *lex, t_minishell *sh, int nb_cmds);

/* CHECK_FOR_SPACES_C */
char	*add_spaces_around_ops(char *line, t_minishell *sh);

/* IS_HELPERS_C */
int		is_redir(char c);
int		is_pipes(char c);
int		is_double_op(char *str, int i);
int		is_third_op(char *str, int i);
bool	is_wspace(char c);

/* CHECK_FILENAME_C */
int		check_filename(char *str);

#endif
