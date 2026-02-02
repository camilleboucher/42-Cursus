/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:13:37 by Camille           #+#    #+#             */
/*   Updated: 2026/01/06 16:35:45 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_logic(t_stack *a, t_stack *b)
{
	if (a->nodes_count == 2)
	{
		if (a->head->nb > a->tail->nb)
			swap(a, true);
	}
	else if (a->nodes_count == 3)
		sort_3(a);
	else if (a->nodes_count >= 4 && a->nodes_count <= 6)
		sort_456(a, b);
	else
	{
		if (is_sorted(a))
			return ;
		rank(a);
		algorithm_butterfly(a, b);
	}
}

void	rank(t_stack *a)
{
	int		i;
	t_node	*next_smallest;

	i = 1;
	next_smallest = find_smallest_nb(a);
	next_smallest->rank = 1;
	while (find_next_smallest_nb(a, &next_smallest))
	{
		i++;
		next_smallest->rank = i;
	}
}

t_node	*find_next_smallest_nb(t_stack *stack, t_node **save_in)
{
	int		prev_smallest;
	t_node	*next_smallest;

	prev_smallest = (*save_in)->nb;
	next_smallest = NULL;
	stack->current = stack->head;
	while (stack->current)
	{
		if (stack->current->nb > prev_smallest)
		{
			if (!next_smallest || next_smallest->nb > stack->current->nb)
				next_smallest = stack->current;
		}
		stack->current = stack->current->next;
	}
	*save_in = next_smallest;
	return (next_smallest);
}
