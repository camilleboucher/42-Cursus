/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:10 by Camille           #+#    #+#             */
/*   Updated: 2026/02/26 15:59:46 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stdio.h"
#include "pipex.h"

static void	get_cmds(char *argv[], t_pipex *pipex);
static void	free_cmds_exit(char **cmds[2]);

int main(int argc, char *argv[], char *env[])
{
	t_pipex	pipex;

	if (argc != 5)
	{
		ft_printf("pipex: the pipex program takes 4 arguments\n");
		return (EXIT_FAILURE);
	}
	get_cmds(argv, &pipex);
	(void)env;
	free_cmds_exit(pipex.cmds);
	return (EXIT_SUCCESS);
}

#include "strutils.h"
static void	get_cmds(char *argv[], t_pipex *pipex)
{
	char	**cmds[2];

	cmds[0] = ft_split(argv[3], ' ');
	cmds[1] = ft_split(argv[4], ' ');
	if (!cmds[0] || !cmds[1])
		free_cmds_exit(cmds);
	pipex->cmds = cmds;
}

#include <stdint.h>
void	free_cmds_exit(char **cmds[2])
{
	uint8_t	i;
	uint8_t	j;

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
	exit(EXIT_FAILURE);
}
