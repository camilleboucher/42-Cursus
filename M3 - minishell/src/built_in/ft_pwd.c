/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 10:39:07 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/04 16:11:51 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_minishell *sh, t_cmd *cmd)
{
	char	*pwd_path;

	(void)cmd;
	pwd_path = getcwd(NULL, 0);
	if (!pwd_path)
		ft_dprintf(2,
			"minishell: pwd: The directory has been deleted\n", sh->cwd);
	else
	{
		printf("%s\n", pwd_path);
		free(pwd_path);
	}
	return (EXIT_SUCCESS);
}
