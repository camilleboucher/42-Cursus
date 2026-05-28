/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:30:58 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/07 14:14:32 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(t_minishell *sh, t_cmd *cmd)
{
	int	i;

	i = 1;
	if (sh->nb_cmds > 1 || !cmd->argv[1])
		return (EXIT_SUCCESS);
	while (cmd->argv[i])
	{
		ft_unset_env(cmd->argv[i], sh);
		i++;
	}
	return (EXIT_SUCCESS);
}
