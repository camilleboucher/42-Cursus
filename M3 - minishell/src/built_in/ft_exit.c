/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:54:50 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/12 15:38:07 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_if_number_invalid(t_minishell *sh, char *number);
static char	*skip_space(char *nptr);
static long	extract_exit_code(t_minishell *sh, char *number);
static void	exit_if_in_parent(t_minishell *sh, int nb_cmds, long exit_c);

int	ft_exit(t_minishell *sh, t_cmd *cmd)
{
	long	exit_c;
	int		argc;

	argc = get_argc(cmd->argv);
	if (cmd->argv[1])
	{
		exit_if_number_invalid(sh, cmd->argv[1]);
		exit_c = extract_exit_code(sh, cmd->argv[1]);
	}
	if (argc > 2)
	{
		ft_dprintf(2, "minishell: exit: too many arguments\n");
		return (EXIT_FAILURE);
	}
	else if (argc == 1)
		exit_if_in_parent(sh, sh->nb_cmds, sh->exit_c);
	if (sh->nb_cmds == 1)
		exit_if_in_parent(sh, sh->nb_cmds, exit_c);
	return (exit_c);
}

static void	exit_if_number_invalid(t_minishell *sh, char *number)
{
	int	i;

	i = 0;
	number = skip_space(number);
	if (number[0] == '-' || number[0] == '+')
		number++;
	while (number[i])
	{
		if (ft_isdigit(number[i]))
			i++;
		else
		{
			if (sh->nb_cmds == 1)
				ft_dprintf(2, "exit\n");
			ft_dprintf(2, "minishell: exit: ");
			ft_dprintf(2, "%s: numeric argument required\n", number);
			cleaning(sh, sh->nb_cmds);
			exit(2);
		}
	}
}

static char	*skip_space(char *nptr)
{
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	return (nptr);
}

static long	extract_exit_code(t_minishell *sh, char *number)
{
	long	exit_c;
	char	*overflowed;

	exit_c = ft_strtol(number, &overflowed);
	if (overflowed)
	{
		if (sh->nb_cmds == 1)
			ft_dprintf(2, "exit\n");
		ft_dprintf(2, "minishell: exit: ");
		ft_dprintf(2, "%s: numeric argument required\n", number);
		cleaning(sh, sh->nb_cmds);
		exit(2);
	}
	if (exit_c < 0 || exit_c > 255)
		exit_c %= 256;
	return (exit_c);
}

static void	exit_if_in_parent(t_minishell *sh, int nb_cmds, long exit_c)
{
	if (nb_cmds == 1)
		ft_dprintf(2, "exit\n");
	cleaning(sh, sh->nb_cmds);
	exit(exit_c);
}
