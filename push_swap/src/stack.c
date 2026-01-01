/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:10:48 by Camille           #+#    #+#             */
/*   Updated: 2026/01/01 12:09:55 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	init_stack(int nb, t_stack *stack, char name)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (false);
	node->nb = nb;
	node->prev = NULL;
	node->next = NULL;
	stack->name = name;
	stack->count = 2;
	stack->head = node;
	stack->tail = node;
	stack->current = node;
	return (true);
}

bool	has_duplicate(int nb, t_stack *a)
{
	a->current = a->head;
	while (1)
	{
		if (nb == a->current->nb)
			return (true);
		a->current = a->current->next;
		if (a->current == a->tail || !a->current)
			break;
	}
	return (false);
}

void	free_stack(t_stack *stack)
{
	if (stack->count)
	{
		stack->count--;
		while (stack->count)
		{
			stack->current = stack->head;
			stack->head = stack->current->next;
			free(stack->current);
			stack->count--;
		}
	}
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = 1;
	stack->current = stack->head;
	while (i < stack->count)
	{
		ft_printf("Node %d [%p]:	%d	prev[%p]	next[%p]\n",
			i, stack->current, stack->current->nb,
			stack->current->prev, stack->current->next);
		stack->current = stack->current->next;
		i++;
	}
}
