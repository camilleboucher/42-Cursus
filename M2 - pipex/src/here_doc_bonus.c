/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/03/07 16:01:34 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stdio.h"
#include "get_next_line.h"
#include "pipex.h"
#include "strutils.h"
#include "here_doc_bonus.h"

int	get_fd_heredoc(char *limiter, int size)
{
	int		fds[2];
	char	*line;

	if (pipe(fds) == -1)
		error_exit(NULL, 0);
	line = NULL;
	limiter = ft_strjoin(limiter, "\n");
	if (!limiter)
		error_exit(NULL, 0);
	size++;
	while (1)
	{
		ft_printf("> ");
		line = get_next_line(STDIN_FILENO);
		if ((int)ft_strlen(line) == size && !ft_strncmp(line, limiter, size))
		{
			free(line);
			break ;
		}
		ft_dprintf(fds[1], line);
		free(line);
	}
	free(limiter);
	close(fds[OUT]);
	return (fds[IN]);
}


