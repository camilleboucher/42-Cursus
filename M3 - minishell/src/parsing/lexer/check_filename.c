/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:06:45 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/07 16:04:58 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_filename(char *str)
{
	int	i;

	i = 0;
	if (is_redir(str[i]) || is_pipes(str[i]))
	{
		ft_dprintf(2, "Syntax Error : %s is an invalid token\n", str);
		return (0);
	}
	while (str && str[i])
	{
		if (str[i] == '/' && (!str[i + 1]))
		{
			ft_dprintf(2, "Minishell: %s: Is a directory\n", str);
			return (0);
		}
		i++;
	}
	return (1);
}
