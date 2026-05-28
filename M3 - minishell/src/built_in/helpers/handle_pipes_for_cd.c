/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipes_for_cd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:14:00 by Camille           #+#    #+#             */
/*   Updated: 2026/05/12 14:31:21 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	handle_pipes_for_cd(t_minishell *sh, int nb_cmds, char **argv)
{
	int	argc;

	argc = get_argc(argv);
	if (argc > 2)
		ft_dprintf(2, "minishell: cd: too many arguments\n");
	else if (access(argv[1], F_OK) == -1)
		perror("minishell");
	else
	{
		cleaning(sh, nb_cmds);
		exit(EXIT_SUCCESS);
	}
	return (true);
}
