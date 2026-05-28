/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:42:57 by Camille           #+#    #+#             */
/*   Updated: 2026/04/29 15:25:09 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_last_argv_i_option_n(char **argv);
static void	print_echo_argv(int argc, char **argv, int argv_i);

int	ft_echo(t_minishell *sh, t_cmd *cmd)
{
	int	argc;
	int	last_argv_i_option_n;

	(void)sh;
	argc = get_argc(cmd->argv);
	last_argv_i_option_n = get_last_argv_i_option_n(cmd->argv);
	print_echo_argv(argc, cmd->argv, last_argv_i_option_n + 1);
	if (!last_argv_i_option_n)
		printf("\n");
	return (EXIT_SUCCESS);
}

static int	get_last_argv_i_option_n(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] != '-')
			return (i - 1);
		j = 1;
		while (argv[i][j])
		{
			if (argv[i][j] != 'n')
				return (i - 1);
			j++;
		}
		i++;
	}
	return (i - 1);
}

static void	print_echo_argv(int argc, char **argv, int argv_i)
{
	while (argv_i < argc)
	{
		printf("%s", argv[argv_i]);
		if (argv_i + 1 < argc)
			printf(" ");
		argv_i++;
	}
}
