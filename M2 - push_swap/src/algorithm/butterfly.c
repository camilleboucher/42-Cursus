/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:47:23 by Camille           #+#    #+#             */
/*   Updated: 2026/01/16 13:56:10 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm_butterfly(t_stack *a, t_stack *b)
{
	phase_1(a, b);
	phase_2(a, b);
}

void	phase_1(t_stack *a, t_stack *b)
{
	int	limiter;

	limiter = 8 + 1 * (a->nodes_count / 20);
	while (a->head)
	{
		if (a->head->rank < b->nodes_count)
		{
			push(a, b);
			rotate(b, true);
		}
		else if (a->head->rank < limiter + b->nodes_count)
			push(a, b);
		else
			rotate(a, true);
	}
}

void	phase_2(t_stack *a, t_stack *b)
{
	int	count;

	while (b->head)
	{
		count = count_until_bigest_rank(b);
		if (!count)
			;
		else if (count < b->nodes_count / 3)
		{
			while (count--)
				rotate(b, true);
		}
		else
		{
			count = b->nodes_count - count;
			while (count--)
				reverse_rotate(b, true);
		}
		push(b, a);
	}
}

int	count_until_bigest_rank(t_stack *b)
{
	int	i;

	i = 0;
	b->current = b->head;
	while (b->current->rank != b->nodes_count)
	{
		i++;
		b->current = b->current->next;
	}
	return (i);
}
