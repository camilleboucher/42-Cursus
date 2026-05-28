/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:55:55 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/10 13:15:21 by lifranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	copy_value(char *ret, int *j, char *val)
{
	int	i;

	i = 0;
	while (val && val[i])
	{
		if (val[i] == '\"')
			ret[(*j)++] = '\x01';
		else if (val[i] == '\'')
			ret[(*j)++] = '\x02';
		else
			ret[(*j)++] = val[i];
		i++;
	}
}

static int	expand_var(char *s, char *ret, t_minishell *shell, int *j)
{
	int		i;
	char	*var;

	i = 0;
	if (s[i] == '$' && s[i + 1] == '?')
	{
		if (!g_signal)
			var = ft_itoa(shell->exit_c);
		else
			var = ft_itoa(g_signal);
		copy_value(ret, j, var);
		free(var);
		i += 2;
	}
	else if (s[i] == '$' && (ft_isalnum(s[i + 1]) || s[i + 1] == '_'))
	{
		var = get_var_name(&s[i]);
		copy_value(ret, j, get_var(shell->envp, var));
		i += ft_strlen(var) + 1;
		free(var);
	}
	return (i);
}

static void	handle_expand(char *s, char *ret, t_minishell *shell)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s && s[i])
	{
		if (s[i] == '$' && !is_in_sq(s, i) && (ft_isalnum(s[i + 1])
				|| s[i + 1] == '_' || s[i + 1] == '?'))
			i += expand_var(&s[i], ret, shell, &j);
		else if (s[i] == '$' && (s[i + 1] == '\"' || s[i + 1] == '\'')
			&& !is_in_quotes(s, i))
			i += 1;
		else
			ret[j++] = s[i++];
	}
}

char	*expand(char *str, t_minishell *shell)
{
	char	*ret;
	int		size;

	size = get_size(str, shell, 0);
	if (size == -1)
		return (NULL);
	ret = ft_calloc(size + 1, sizeof(char));
	if (!ret)
		return (NULL);
	handle_expand(str, ret, shell);
	ret[size] = '\0';
	return (ret);
}
