/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:41:17 by lifranco          #+#    #+#             */
/*   Updated: 2026/04/23 16:45:14 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
		i++;
	return (i);
}

void	fill_argv(t_minishell *sh, t_cmd *cmd, char *word)
{
	int		i;
	int		size;
	char	**args;

	i = 0;
	size = count_split(cmd->argv);
	args = ft_calloc(size + 2, sizeof(char *));
	if (!args)
		error_exit(sh, sh->nb_cmds);
	while (i < size)
	{
		args[i] = cmd->argv[i];
		i++;
	}
	args[size] = ft_strdup(word);
	args[size + 1] = NULL;
	free(cmd->argv);
	cmd->argv = args;
}
