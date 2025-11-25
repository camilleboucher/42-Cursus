/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:58:45 by Camille           #+#    #+#             */
/*   Updated: 2025/11/24 17:49:29 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*buf;
	char		*line;
	ssize_t		size_read;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	line = NULL;
	buf = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	size_read = 1;
	while (size_read > 0)
	{
		size_read = read_and_set_buf(&buf, fd);
		if (!fill_stash(&stash[fd], buf))
			break ;
		if (ft_strchr(stash[fd], '\n'))
			break ;
	}
	free(buf);
	if (size_read >= 0)
		line = extract_line(&stash[fd]);
	return (line);
}

int	fill_stash(char **stash, char *buf)
{
	char	*old_stash;

	old_stash = *stash;
	if (!*stash)
		*stash = ft_strjoin("", buf);
	else
		*stash = ft_strjoin(*stash, buf);
	if (old_stash)
		free(old_stash);
	if (!*stash)
		return (0);
	return (1);
}

char	*extract_line(char **stash)
{
	char	*old_stash;
	char	*line;
	char	*end_of_line;

	if (!*stash)
		return (NULL);
	line = NULL;
	end_of_line = ft_strchr(*stash, '\n');
	if (!end_of_line)
	{
		if (**stash)
			line = ft_substr(*stash, 0, ft_strlen(*stash));
		free(*stash);
		*stash = NULL;
	}
	else
	{
		line = ft_substr(*stash, 0, end_of_line - *stash + 1);
		old_stash = *stash;
		*stash = ft_substr(end_of_line, 1, ft_strlen(*stash));
		free(old_stash);
	}
	return (line);
}

ssize_t	read_and_set_buf(char **buf, int fd)
{
	ssize_t	size_read;

	size_read = read(fd, *buf, (size_t)BUFFER_SIZE);
	if (size_read < 0)
	{
		free(*buf);
		*buf = NULL;
	}
	else
		(*buf)[size_read] = '\0';
	return (size_read);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*sub_s;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start > size)
	{
		sub_s = malloc(1);
		if (sub_s)
			return (NULL);
		sub_s[0] = '\0';
		return (sub_s);
	}
	size -= start;
	if (len < size)
		size = len;
	sub_s = malloc(sizeof(char) * (size + 1));
	if (!sub_s)
		return (NULL);
	ft_strlcpy(sub_s, s + start, size + 1);
	sub_s[size] = '\0';
	return (sub_s);
}
