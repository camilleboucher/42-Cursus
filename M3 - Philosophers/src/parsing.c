/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <private_mail>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:33:45 by cboucher          #+#    #+#             */
/*   Updated: 2026/06/27 22:44:15 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	check_limit(char *s);

bool	check_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("%s%s%s%s", USAGE_MSG1, USAGE_MSG2, USAGE_MSG3, USAGE_MSG4);
		return (false);
	}
	argc--;
	while (argc && check_limit(argv[argc]) && ft_aredigits(argv[argc]))
		argc--;
	if (argc)
	{
		printf("%s%s%s%s", USAGE_MSG1, USAGE_MSG2, USAGE_MSG3, USAGE_MSG4);
		printf("%s", USAGE_MAX_LIMIT_MSG);
		return (false);
	}
	return (true);
}

bool	check_limit_val(t_ctx *ctx, int argc)
{
	if (ctx->nb_philos > 120000 || ctx->time_to_die > 120000
		|| ctx->time_to_eat > 120000 || ctx->time_to_sleep > 120000)
		return (false);
	if (argc == 6 && ctx->nb_times_must_eat > 120000)
		return (false);
	return (true);
}

static bool	check_limit(char *s)
{
	int	i;

	i = 0;
	while (s[i] && i < 7)
		i++;
	if (i > 6)
		return (false);
	return (true);
}
