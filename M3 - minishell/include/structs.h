/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:25:25 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/12 16:56:55 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_type
{
	WORDS,
	FILENAME,
	PIPES,
	IN,
	OUT,
	LIM,
	APP
}	t_type;

typedef struct s_lexer
{
	char			*content;
	int				type;
	struct s_lexer	*next;
}	t_lexer;

typedef struct s_minishell
{
	char			*prompt;
	char			*cwd;
	char			*first_home_dir_path;
	char			**envp;
	int				exit_c;
	bool			parse_err;
	size_t			nb_cmds;
	struct s_cmd	**cmds;
	struct s_io		**ios;
}	t_minishell;

typedef struct s_cmd
{
	char	*path;
	char	**argv;
	int		fds[2];
	pid_t	pid;
	int		(*built_in)(t_minishell *, struct s_cmd *);
}	t_cmd;

typedef struct s_io
{
	char		*infile;
	char		*outfile;
	bool		is_lim;
	bool		expand_heredoc;
	int			outfile_flags;
	bool		invalid;
	struct s_io	*next;
}	t_io;

#endif
