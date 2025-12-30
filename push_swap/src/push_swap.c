/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:27:15 by Camille           #+#    #+#             */
/*   Updated: 2025/12/23 12:11:23 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_atoi_safe(const char *nptr, int *nb, t_positions *pos)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	while (*nptr)
	{
		if(!ft_isdigit(*nptr))
			trigger_error(pos);
		nbr *= 10;
		nbr += *nptr - '0';
		if (nbr * sign > INT_MAX || nbr * sign < INT_MIN)
			return (false);
		nptr++;
	}
	*nb = (int)nbr * sign;
	return (true);
}

static bool	parsing(int argc, char **argv, t_stack **a, t_positions *pos)
{
	int	nb;

	if (argv[1][0] && ft_atoi_safe(argv[1], &nb, pos))
	{
		*a = stack_new(nb);
		if (!*a)
			return (false);
	}
	init_positions(pos, 2, *a);
	while (pos->count != argc)
	{
		if (argv[pos->count][0] && ft_atoi_safe(argv[pos->count], &nb, pos))
		{
			if (hasDuplicates(nb, *a) || !stack_add(nb, pos))
				return (false);
		}
		else
			return (false);
		pos->count++;
	}
	(*a)->prev = pos->tail;
	(*a)->prev->next = *a;
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_positions	pos;

	if (argc == 1)
		return (1);
	a = NULL;
	pos.count = 0;
	if (!parsing(argc, argv, &a, &pos))
		trigger_error( &pos);
	if (argc == 2)
		freeStack(&pos);
	//printStack(a, &pos);
	freeStack( &pos);
	return (0);
}

void	trigger_error(t_positions *pos)
{
	if (pos->count)
		freeStack(pos);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
