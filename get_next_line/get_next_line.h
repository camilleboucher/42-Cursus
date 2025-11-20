/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:53:07 by Camille           #+#    #+#             */
/*   Updated: 2025/11/15 16:34:02 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
    #define BUFFER_SIZE 10
# endif

typedef struct s_buf
{
	char	*data;
	ssize_t	size;
} t_buf;

/*	get_next_line.c			*/
char	*get_next_line(int fd);
t_buf	*fill_buf(int fd);
char	*fill_leftover(char *s_leftover, char *buf);
char	*extract_line(char *s_leftover);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*	get_next_line_utils.c	*/

char	*ft_strchr(const char *s, size_t c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
