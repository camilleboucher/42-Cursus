/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:53:07 by Camille           #+#    #+#             */
/*   Updated: 2025/11/24 17:42:59 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/*	get_next_line_bonus.c			*/
char	*get_next_line(int fd);
int		fill_stash(char **stash, char *buf);
char	*extract_line(char **stash);
ssize_t	read_and_set_buf(char **buf, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*	get_next_line_utils_bonus.c		*/

char	*ft_strchr(const char *s, size_t c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

#endif
