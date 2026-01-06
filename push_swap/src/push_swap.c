/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:27:15 by Camille           #+#    #+#             */
/*   Updated: 2026/01/06 11:06:30 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_atoi_safe(const char *nptr, int *nb, t_stack *a);
static bool	parsing(int argc, char **argv, t_stack *a);
static void	init_stack_b(t_stack *stack);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (1);
	if (!parsing(argc - 1, argv, &a))
		trigger_error(&a);
	if (argc == 2)
		free_stack(&a);
	a.nodes_count = argc - 1;
	init_stack_b(&b);
	main_logic(&a, &b);
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

	if (argv[argc][0] && ft_atoi_safe(argv[argc], &nb, a))
	{
		if(!init_stack_a(nb, a))
			return (false);
	}
	while (--argc)
	{
		if (argv[argc][0] && ft_atoi_safe(argv[argc], &nb, a))
		{
			if (has_duplicate(nb, a) || !add_node(nb, a))
				return (false);
		}
		else
			return (false);
	}
	return (true);
}

static void	init_stack_b(t_stack *b)
{
	b->name = 'b';
	b->nodes_count = 0;
	b->head = NULL;
	b->tail = NULL;
	b->current = NULL;
}
