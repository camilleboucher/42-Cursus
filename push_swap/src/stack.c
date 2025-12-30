/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:10:48 by Camille           #+#    #+#             */
/*   Updated: 2025/12/23 12:09:40 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int nb)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nb = nb;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

bool	stack_add(int nb, t_positions *pos)
{
	t_stack	*node;

	node = stack_new(nb);
	if (!node)
		return (false);
	pos->tail->next = node;
	node->prev = pos->tail;
	pos->tail = node;
	return (true);
}

bool	hasDuplicates(int nb, t_stack *a)
{
	while (a)
	{
		if (nb == a->nb)
			return (true);
		a = a->next;
	}
	return (false);
}

void	freeStack(t_positions *pos)
{
	if (pos->count)
	{
		pos->count--;
		while (pos->count)
		{
			pos->current = pos->head;
			pos->head = pos->current->next;
			free(pos->current);
			pos->count--;
		}
	}
}

void	printStack(t_stack *a, t_positions *pos)
{
	int	i;

	i = 1;
	while (i < pos->count)
	{
		ft_printf("Node %d [%p]:	%d	prev[%p]	next[%p]\n",
			i, a, a->nb, a->prev, a->next);
		a = a->next;
		i++;
	}
	ft_printf("count %d", pos->count);
}
