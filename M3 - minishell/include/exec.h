/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:31:30 by Camille           #+#    #+#             */
/*   Updated: 2026/05/12 16:02:49 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# define WARN_EOF "mini%s at line %d delimited by end-of-file (wanted `%s')\n"
# define EXIT_NOTFOUND 127
# define EXIT_NOTEXECUTABLE 126

// exec.c
int		exec(t_minishell *sh, int nb_cmds);

// built-in.c
bool	is_builtin_for_parent(t_cmd *cmd, char *bin);
bool	set_built_in(t_cmd *cmd, char *bin);

// redirections.c
bool	set_redirections(t_minishell *sh, t_cmd *cmd, t_io *io);

// fds_utils.c
void	close_fds(int (*fds)[2]);
void	close_fd(int *fd);
void	duplicate_fds(t_cmd *cmd);
void	close_all_fds(t_cmd **cmds, int nb_cmds);

// heredoc.c
int		get_fd_heredoc(t_minishell *sh, t_io *io);

// pipes.c
void	set_pipe(t_minishell *sh, int *curr_cmd_fd_out, int *next_cmd_fd_in);

// children.c
void	make_child(t_minishell *sh, t_cmd *cmd, char **env_path);
void	wait_children(t_cmd **cmds, int nb_cmds, int *wstatus);

// exit_code.c
int		get_exit_code(bool io_invalid, t_cmd *cmd, int wstatus);
int		parse_wait_status(int wstatus);

#endif
