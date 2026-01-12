/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:10:48 by Camille           #+#    #+#             */
/*   Updated: 2026/01/06 10:57:12 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

bool	init_stack_a(int nb, t_stack *stack)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (false);
	node->nb = nb;
	node->rank = 0;
	node->prev = NULL;
	node->next = NULL;
	stack->name = 'a';
	stack->head = node;
	stack->tail = node;
	stack->current = node;
	return (true);
}

bool	has_duplicate(int nb, t_stack *a)
{
	a->current = a->head;
	while (a->current)
	{
		if (nb == a->current->nb)
			return (true);
		a->current = a->current->next;
	}
	return (false);
}

bool	add_node(int nb, t_stack *stack)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (false);
	stack->head->prev = node;
	node->nb = nb;
	node->rank = 0;
	node->prev = NULL;
	node->next = stack->head;
	stack->head = node;
	return (true);
}

void	free_stack(t_stack *stack)
{
	stack->current = stack->head;
	while (stack->current)
	{
		stack->head = stack->current->next;
		free(stack->current);
		stack->current = stack->head;
	}
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = 1;
	stack->current = stack->head;
	ft_printf("STACK %c :\n=====================\n", stack->name);
	while (stack->current)
	{
		ft_printf("Node %d [%p]:	%d(rank %d)	prev[%p]	next[%p]\n",
			i, stack->current, stack->current->nb, stack->current->rank,
			stack->current->prev, stack->current->next);
		stack->current = stack->current->next;
		i++;
	}
}
