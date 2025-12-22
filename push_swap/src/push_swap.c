/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:27:15 by Camille           #+#    #+#             */
/*   Updated: 2025/12/22 15:46:56 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_atoi_safe(const char *nptr, int *nb)
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
			return (false);
		nbr *= 10;
		nbr += *nptr - '0';
		nptr++;
	}
	nbr *= sign;
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (false);
	*nb = (int)nbr;
	return (true);
}

static bool	parsing(int argc, char **argv, t_stack **a)
{
	t_stack	*node;
	int		i;
	int		nb;

	i = 1;
	node = NULL;
	while (i != argc)
	{
		if (argv[i][0] && ft_atoi_safe(argv[i], &nb))
		{
			node = stack_new(nb);
			if (!node)
				return (false);
			//stack_add(node, a, a);
		}
		else
			return (false);
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc == 1)
		return (1);
	a = NULL;
	if (!parsing(argc, argv, &a))
		trigger_error(&a);
	if (argc == 2)
		return (0);
	return (0);
}

void	trigger_error(t_stack **stack)
{
	if (*stack)
	{
		//free stack
	}
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
