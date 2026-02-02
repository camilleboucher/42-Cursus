/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:55:48 by Camille           #+#    #+#             */
/*   Updated: 2026/01/06 15:14:06 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_node	*head;

	head = stack->head;
	while (head)
	{
		stack->current = head->next;
		while (stack->current)
		{
			if (head->nb > stack->current->nb)
				return (false);
			stack->current = stack->current->next;
		}
		head = head->next;
	}
	return (true);
}

t_node	*find_smallest_nb(t_stack *stack)
{
	t_node	*smallest;

	stack->current = stack->head;
	smallest = stack->current;
	while (stack->current)
	{
		if (smallest->nb > stack->current->nb)
			smallest = stack->current;
		stack->current = stack->current->next;
	}
	return (smallest);
}

t_node	*find_first_nb_bigger_than(t_stack *sorted_stack, int nb)
{
	t_node	*finding;
	t_node	*smallest;

	finding = NULL;
	sorted_stack->current = sorted_stack->head;
	smallest = sorted_stack->current;
	while (sorted_stack->current)
	{
		if (smallest->nb > sorted_stack->current->nb)
			smallest = sorted_stack->current;
		if (sorted_stack->current->nb > nb)
		{
			if (!finding)
				finding = sorted_stack->current;
			else if (finding->nb > sorted_stack->current->nb)
				finding = sorted_stack->current;
		}
		sorted_stack->current = sorted_stack->current->next;
	}
	if (!finding)
		return (smallest);
	return (finding);
}

void	positionning_head(t_stack *stack, t_node *to)
{
	int		distance;
	void	(*good_rotation)(t_stack *, bool);

	distance = 0;
	stack->current = stack->head;
	while (stack->current != to)
	{
		stack->current = stack->current->next;
		distance++;
	}
	if (distance > (stack->nodes_count / 2))
	{
		distance = stack->nodes_count - distance;
		good_rotation = reverse_rotate;
	}
	else
		good_rotation = rotate;
	while (distance)
	{
		good_rotation(stack, true);
		distance--;
	}
}
