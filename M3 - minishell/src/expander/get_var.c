/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:23:08 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/07 17:23:54 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var(char **envp, char *var)
{
	int		i;
	int		size;
	char	*equal;

	equal = ft_strjoin(var, "=");
	if (!equal)
		return (NULL);
	if (!envp || !*envp)
	{
		free(equal);
		return (NULL);
	}
	i = 0;
	size = ft_strlen(equal);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], equal, size) == 0)
		{
			free(equal);
			return (envp[i] + size);
		}
		i++;
	}
	free(equal);
	return (NULL);
}

char	*get_var_name(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 1;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && (ft_isalnum(str[i]) == 1 || str[i] == '_'))
		i++;
	ret = ft_calloc(i + 1, sizeof(char));
	if (!ret)
		return (NULL);
	i = 1;
	while (str[i] && (ft_isalnum(str[i]) == 1 || str[i] == '_'))
		ret[j++] = str[i++];
	ret[j] = '\0';
	return (ret);
}

static int	handle_var_size(char *str, int *i, t_minishell *shell, int *size)
{
	char	*var;
	char	*value;

	var = get_var_name(&str[*i]);
	if (!var)
		return (-1);
	*size -= ft_strlen(var) + 1;
	value = get_var(shell->envp, var);
	if (value)
		*size += ft_strlen(value);
	*i += ft_strlen(var) + 1;
	free(var);
	return (0);
}

int	get_size(char *str, t_minishell *shell, int i)
{
	char	*var;
	int		size;

	size = ft_strlen(str);
	while (str && str[i])
	{
		if (!is_in_sq(str, i) && str[i] == '$' && str[i + 1] == '?')
		{
			size -= 2;
			var = ft_itoa(shell->exit_c);
			size += ft_strlen(var);
			free(var);
			i += 2;
		}
		else if (!is_in_sq(str, i) && str[i] == '$'
			&& (ft_isalnum(str[i + 1]) == 1 || str[i + 1] == '_'))
		{
			if (handle_var_size(str, &i, shell, &size) == -1)
				return (-1);
		}
		else
			i++;
	}
	return (size);
}
