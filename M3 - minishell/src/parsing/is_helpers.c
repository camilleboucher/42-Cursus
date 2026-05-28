/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:26:36 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/12 14:12:04 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_double_op(char *str, int i)
{
	return (i > 0 && str[i - 1] == str[i]);
}

int	is_third_op(char *str, int i)
{
	return (i > 1 && str[i - 1] == str[i] && str[i - 2] == str[i]);
}

int	is_redir(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}

int	is_pipes(char c)
{
	if (c == '|')
		return (1);
	return (0);
}

bool	is_wspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}
