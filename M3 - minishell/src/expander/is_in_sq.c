/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_sq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:08:56 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/13 14:21:37 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_in_sq(char *str, int pos)
{
	int		i;
	bool	sq;
	bool	dq;

	dq = false;
	sq = false;
	i = 0;
	while (i < pos)
	{
		if (str[i] == '\'' && !dq)
			sq = !sq;
		else if (str[i] == '\"' && !sq)
			dq = !dq;
		i++;
	}
	return (sq);
}
