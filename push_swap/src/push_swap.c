/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:27:15 by Camille           #+#    #+#             */
/*   Updated: 2026/01/01 12:12:42 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_atoi_safe(const char *nptr, int *nb, t_stack *a);
static bool	parsing(int argc, char **argv, t_stack *a);

int	main(int argc, char **argv)
{
	t_stack	a;

	if (argc == 1)
		return (1);
	if (!parsing(argc, argv, &a))
		trigger_error(&a);
	if (argc == 2)
		free_stack(&a);
	main_logic(&a);
	free_stack(&a);
	return (0);
}

void	trigger_error(t_stack *a)
{
	if(a)
		free_stack(a);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static bool	ft_atoi_safe(const char *nptr, int *nb, t_stack *a)
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
			trigger_error(a);
		nbr *= 10;
		nbr += *nptr - '0';
		if (nbr * sign > INT_MAX || nbr * sign < INT_MIN)
			return (false);
		nptr++;
	}
	*nb = (int)nbr * sign;
	return (true);
}

static bool	parsing(int argc, char **argv, t_stack *a)
{
	int	nb;

	if (argv[1][0] && ft_atoi_safe(argv[1], &nb, a))
	{
		if(!init_stack(nb, a, 'a'))
			return (false);
	}
	while (a->count != argc)
	{
		if (argv[a->count][0] && ft_atoi_safe(argv[a->count], &nb, a))
		{
			if (has_duplicate(nb, a) || !add_node(nb, a))
				return (false);
		}
		else
			return (false);
		a->count++;
	}
	a->head->prev = a->tail;
	return (true);
}
