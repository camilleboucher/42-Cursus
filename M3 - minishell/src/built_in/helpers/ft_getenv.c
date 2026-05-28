/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:29:02 by Camille           #+#    #+#             */
/*   Updated: 2026/05/08 15:18:51 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(const char *name, const char **envp)
{
	int	size;
	int	i;

	if (!name || !envp)
		return (NULL);
	size = ft_strlen(name);
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], name, size))
		{
			if (!envp[i][size])
				return ((char *)(envp[i] + size));
			if (envp[i][size] == '=')
				return ((char *)(envp[i] + size + 1));
		}
		i++;
	}
	return (NULL);
}
