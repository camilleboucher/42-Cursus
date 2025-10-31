/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:12:47 by Camille           #+#    #+#             */
/*   Updated: 2025/10/31 14:20:13 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strs_counter(char *str, char c);
static size_t	strlen_until_sep(char *str, char c);
static void		fill_strs(char *str, char c, char **strs);

char	**ft_split(char const *s, char c)
{
	size_t	nb_strs;
	char	**strs;

	if (!s)
		return (NULL);
	nb_strs = strs_counter((char *)s, c);
	strs = malloc(sizeof(char *) * (nb_strs + 1));
	if (!strs)
		return (NULL);
	strs[nb_strs] = NULL;
	fill_strs((char *)s, c, strs);
	return (strs);
}

static size_t	strs_counter(char *str, char c)
{
	size_t	i;
	size_t	len;
	size_t	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		len = strlen_until_sep(&str[i], c);
		if (len)
		{
			i += len;
			nb++;
		}
		else
			i++;
	}
	return (nb);
}

static size_t	strlen_until_sep(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		else
			i++;
	}
	return (i);
}

static void	fill_strs(char *str, char c, char **strs)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		len = strlen_until_sep(&str[i], c);
		if (len)
		{
			i += len;
			strs[j] = malloc(sizeof(char) * (len + 1));
			k = 0;
			strs[j][len] = '\0';
			while (len)
				strs[j][k++] = str[i - len--];
			j++;
		}
		else
			i++;
	}
}
