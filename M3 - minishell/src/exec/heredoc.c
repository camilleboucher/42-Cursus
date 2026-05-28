/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:59:17 by Camille           #+#    #+#             */
/*   Updated: 2026/05/08 15:39:20 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	heredoc_loop(t_minishell *sh, t_io *io, char *s, int (*fds)[2]);
static void	init_hdoc(char *lim, int *size, int *line_nb, int *fd_stdin_dup);
static bool	sigint_triggered(int fd_stdin_dup, int (*fds)[2]);
static void	print_expanded_hdoc(t_minishell *sh, int fd_w, int fd_r, char *s);

int	get_fd_heredoc(t_minishell *sh, t_io *io)
{
	int		fds[2];
	char	*line;

	if (pipe(fds) == -1)
		error_exit(sh, sh->nb_cmds);
	line = NULL;
	set_signals(true);
	heredoc_loop(sh, io, line, &fds);
	ignore_signals();
	close(fds[1]);
	return (fds[0]);
}

static void	heredoc_loop(t_minishell *sh, t_io *io, char *s, int (*fds)[2])
{
	int	len;
	int	line_nb;
	int	fd_writing;
	int	fd_stdin_dup;

	init_hdoc(io->infile, &len, &line_nb, &fd_stdin_dup);
	fd_writing = (*fds)[1];
	while (1)
	{
		s = readline("> ");
		if (sigint_triggered(fd_stdin_dup, fds))
			break ;
		if (!s)
			printf(WARN_EOF, "shell: warning: heredoc", line_nb, io->infile);
		if (!s || ((int)ft_strlen(s) == len && !ft_strncmp(s, io->infile, len)))
			break ;
		if (io->expand_heredoc)
			print_expanded_hdoc(sh, fd_writing, fd_stdin_dup, s);
		else
			ft_dprintf(fd_writing, "%s\n", s);
		free(s);
		line_nb++;
	}
	free(s);
	close(fd_stdin_dup);
}

static void	init_hdoc(char *lim, int *size, int *line_nb, int *fd_stdin_dup)
{
	*size = ft_strlen(lim);
	*line_nb = 1;
	*fd_stdin_dup = dup(STDIN_FILENO);
}

static bool	sigint_triggered(int fd_stdin_dup, int (*fds)[2])
{
	if (g_signal == SIGINT)
	{
		dup2(fd_stdin_dup, STDIN_FILENO);
		close(fd_stdin_dup);
		close_fd(&(*fds)[0]);
		return (true);
	}
	return (false);
}

static void	print_expanded_hdoc(t_minishell *sh, int fd_w, int fd_r, char *s)
{
	char	*expanded_line;

	expanded_line = expand(s, sh);
	if (!expanded_line)
	{
		free(s);
		close(fd_r);
		close(fd_w);
		error_exit(sh, sh->nb_cmds);
	}
	ft_dprintf(fd_w, "%s\n", expanded_line);
	free(expanded_line);
}
