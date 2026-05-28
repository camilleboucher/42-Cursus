/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cleaning.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:49:09 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/04 17:27:45 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_parsing(t_lexer *lex, t_minishell *sh, int nb_cmds)
{
	if (lex)
		ft_lexclear(&lex, del);
	error_exit(sh, nb_cmds);
}
