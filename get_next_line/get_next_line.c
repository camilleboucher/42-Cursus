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
#include <unistd.h>


char	*get_next_line(int fd)
{
	static char	*s_leftover = NULL;
	t_buf		*buf;
	char		*line;

	buf = NULL;
	while (!s_leftover || !ft_strchr(s_leftover, '\n'))
	{
		buf = fill_buf(fd);
		if (!buf)
		{
			free(s_leftover);
			return (NULL);
		}
		s_leftover = fill_leftover(s_leftover, buf->data);
		free(buf->data);
		free(buf);
		if (!s_leftover)
			return (NULL);
	}
	line = extract_line(s_leftover);
	return (line);
}

t_buf	*fill_buf(int fd)
{
	t_buf	*buf;

	buf = malloc(sizeof(t_buf));
	if (!buf)
		return (NULL);
	buf->data = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf->data)
	{
		free(buf);
		return (NULL);
	}
	buf->size = read(fd, buf->data, BUFFER_SIZE);
	if (buf->size < 0)
		return (NULL);
	buf->data[buf->size] = '\0';
	return (buf);
}

char	*fill_leftover(char *s_leftover, char *buf)
{
	char	*old_leftover;

	old_leftover = s_leftover;
	if (!s_leftover)
		s_leftover = ft_strjoin("", buf);
	else
		s_leftover = ft_strjoin(s_leftover, buf);
	if (old_leftover)
		free(old_leftover);
	return (s_leftover);
}

char	*extract_line(char *s_leftover)
{
	char	*old_leftover;
	char	*line;
	char	*end_of_line;
	size_t	size_leftover;

	end_of_line = ft_strchr(s_leftover, '\n');
	size_leftover = ft_strlen(s_leftover);
	line = ft_substr(s_leftover, 0, size_leftover);
	if (!end_of_line)
		free(s_leftover);
	else
	{
		old_leftover = s_leftover;
		s_leftover = ft_substr(s_leftover, (end_of_line - s_leftover), size_leftover);
		free(old_leftover);
		if (!s_leftover)
		{
			free(line); //double free du main ou pas ???
			return (NULL);
		}
	}
	return (line);
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
	ft_strlcpy(sub_s, s + start, size); // memcopy a la base....
	sub_s[size] = '\0';
	return (sub_s);
}
