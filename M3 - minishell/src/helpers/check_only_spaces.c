/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_only_spaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:42:01 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/09 15:21:30 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_only_spaces(char *prompt)
{
	int	i;

	i = 0;
	while (prompt && (prompt[i] == ' '
			|| (prompt[i] >= '\t' && prompt[i] <= '\r')))
		i++;
	if (prompt[i] != '\0')
		return (false);
	else
		return (true);
}
