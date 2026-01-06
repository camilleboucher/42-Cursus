/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:21:38 by Camille           #+#    #+#             */
/*   Updated: 2026/01/06 11:08:06 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, bool display_stackname)
{
	int	nb;

	if (!stack->head || !stack->head->next)
		return ;
	nb = stack->head->nb;
	stack->head->nb = stack->head->next->nb;
	stack->head->next->nb = nb;
	ft_putchar_fd('s', 1);
	if (display_stackname)
	{
		ft_putchar_fd(stack->name, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	rotate(t_stack *stack, bool display_stackname)
{
	stack->current = stack->head->next;
	stack->current->prev = NULL;
	stack->head->prev = stack->tail;
	stack->head->next = NULL;
	stack->tail->next = stack->head;
	stack->tail = stack->head;
	stack->head = stack->current;
	ft_putchar_fd('r', 1);
	if (display_stackname)
	{
		ft_putchar_fd(stack->name, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	reverse_rotate(t_stack *stack, bool display_stackname)
{
	stack->current = stack->tail->prev;
	stack->current->next = NULL;
	stack->tail->prev = NULL;
	stack->tail->next = stack->head;
	stack->head->prev = stack->tail;
	stack->head = stack->tail;
	stack->tail = stack->current;
	if (display_stackname)
	{
		ft_putstr_fd("rr", 1);
		ft_putchar_fd(stack->name, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	push(t_stack *from, t_stack *to)
{
	if (!from->head)
		return ;
	from->current = from->head;
	from->head = from->current->next;
	if (from->head)
		from->head->prev = NULL;
	else
		from->tail = NULL;
	from->current->next = to->head;
	from->current->prev = NULL;
	if (to->head)
		to->head->prev = from->current;
	to->head = from->current;
	if (!to->tail)
		to->tail = from->current;
	from->nodes_count--;
	to->nodes_count++;
	ft_putstr_fd("p", 1);
	ft_putchar_fd(to->name, 1);
	ft_putchar_fd('\n', 1);
}
