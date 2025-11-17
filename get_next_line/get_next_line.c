/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:58:45 by Camille           #+#    #+#             */
/*   Updated: 2025/11/15 16:34:01 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static ssize_t	fill_leftover(char *s_leftover, char *buf, int fd);
static ssize_t	fill_buf(char *buf, int fd);
static char		*extract_line(char *s_leftover, ssize_t size_left);

char	*get_next_line(int fd)
{
	static char	*s_leftover = NULL;
	char		*buf;
	char		*line;
	ssize_t		size_left;

	buf = NULL;
	size_left = 0;
	if (!BUFFER_SIZE || fd < 0)
		return (NULL);
	if (!s_leftover || !ft_memchr(s_leftover, '\n', ft_strlen(s_leftover)))
	{
		size_left = fill_leftover(s_leftover, buf, fd);
		free(buf);
		if (!size_left)
			return (NULL);
	}
	if (!size_left)
		size_left = ft_strlen(s_leftover);
	line = extract_line(s_leftover, size_left);
	return (line);
}

static ssize_t	fill_leftover(char *s_leftover, char *buf, int fd)
{
	char	*old_leftover;
	size_t	size_buf;
	size_t	size_left;

	old_leftover = NULL;
	size_buf = fill_buf(buf, fd);
	size_left = ft_strlen(s_leftover);
	while (size_buf && !ft_memchr(s_leftover, '\n', size_buf))
	{
		s_leftover = malloc(sizeof(char) * (size_left + size_buf + 1));
		if (!s_leftover)
			return (0);
		ft_memcpy(s_leftover, old_leftover, size_left);
		free(old_leftover);
		size_left = ft_strlen(s_leftover);
		ft_memcpy((s_leftover + size_left), buf, size_buf);
		s_leftover[size_left + size_buf] = '\0';
		old_leftover = s_leftover;
		size_buf = fill_buf(buf, fd);
	}
	return (size_left);
}

static ssize_t	fill_buf(char *buf, int fd)
{
	ssize_t		reading_size;

	if (buf)
		free(buf);
	buf = malloc(sizeof(char) * (BUFFER_SIZE));
	if (!buf)
		return (0);
	reading_size = read(fd, buf, BUFFER_SIZE);
	if (reading_size <= 0)
		return (0);
	return (reading_size);
}

static char	*extract_line(char *s_leftover, ssize_t size_left)
{
	char	*old_leftover;
	char	*end_of_line;
	char	*line;
	ssize_t	size_line;

	end_of_line = ft_memchr(s_leftover, '\n', ft_strlen(s_leftover));
	if (!end_of_line)
	{
		line = ft_strdup(s_leftover);
		free(s_leftover);
		return (line);
	}
	size_line = end_of_line - s_leftover;
	size_left -= size_line;
	line = malloc(sizeof(char) * (size_line + 1));
	old_leftover = s_leftover;
	s_leftover = malloc(sizeof(char) * (size_left));
	if (!line || !s_leftover)
	{
		free(old_leftover);
		return (NULL);
	}
	ft_memcpy(line, s_leftover, size_line);
	line[size_line] = '\0';
	ft_memcpy(s_leftover, old_leftover + size_line, size_left);
	free(old_leftover);
	return (line);
}
