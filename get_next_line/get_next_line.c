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

static ssize_t	fill_leftover(char *s_leftover, char *buf, int fd);
static ssize_t	fill_buf(char *buf, int fd);

char	*get_next_line(int fd)
{
	static char	*s_leftover = NULL;
	char		*buf;
	//char		*line;

	buf = NULL;
	if (!BUFFER_SIZE || fd < 0 || !fill_leftover(s_leftover, buf, fd))
		return (NULL);
	//extract_line
	free(buf);
	return (buf);
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

/*static void	extract_line(char *leftover)
{
//
}*/
