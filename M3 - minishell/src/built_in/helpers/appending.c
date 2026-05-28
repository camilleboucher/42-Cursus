/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appending.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:30:34 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/12 15:51:38 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_varname_with_equal(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && (ft_isalnum(str[i]) == 1 || str[i] == '_'))
		i++;
	ret = ft_calloc(i + 2, sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i] && (ft_isalnum(str[i]) == 1 || str[i] == '_'))
	{
		ret[j] = str[i];
		j++;
		i++;
	}
	ret[j] = str[i];
	ret[j + 1] = '\0';
	return (ret);
}

int	append(char *env, char *var, char *name, t_minishell *sh)
{
	char	*appended;
	char	*equal;
	char	*full_var;

	appended = ft_strjoin(env, var + ft_strlen(name) + 1);
	if (!appended)
		return (0);
	equal = get_varname_with_equal(var);
	if (!equal)
	{
		free(appended);
		return (0);
	}
	full_var = ft_strjoin(equal, appended);
	free(appended);
	free(equal);
	if (!full_var)
		return (0);
	ft_set_env(full_var, sh);
	free(full_var);
	return (1);
}
