/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/02/26 21:19:54 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "strutils.h"
#include "commands.h"

void	get_cmds(char *argv[], t_pipex *pipex)
{
	char	***cmds;

	cmds = malloc(sizeof(char **) * 2);
	cmds[0] = ft_split(argv[2], ' ');
	cmds[1] = ft_split(argv[3], ' ');
	if (!cmds[0] || !cmds[1])
		free_cmds_and_exit(cmds);
	pipex->cmds = cmds;
}

void	free_cmds(char ***cmds)
{
	uint8_t		i;
	uint16_t	j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (cmds[i][j])
		{
			free(cmds[i][j]);
			j++;
		}
		free(cmds[i]);
		i++;
	}
	free(cmds);
}

void	free_cmds_and_exit(char ***cmds)
{
	perror("pipex");
	free_cmds(cmds);
	exit(EXIT_FAILURE);
}
