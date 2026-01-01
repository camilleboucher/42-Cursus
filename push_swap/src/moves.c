/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:21:38 by Camille           #+#    #+#             */
/*   Updated: 2025/12/30 11:44:03 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, bool display_stackname)
{
	int	nb;

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
	stack->head = stack->head->next;
	stack->tail = stack->head->prev;
	stack->head->prev = stack->tail;
	stack->head->next = stack->head->next;
	ft_putchar_fd('r', 1);
	if (display_stackname)
	{
		ft_putchar_fd(stack->name, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	reverse_rotate(t_stack *stack, bool display_stackname)
{
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
	stack->head->prev = stack->tail;
	stack->head->next = stack->head->next;
	if (display_stackname)
	{
		ft_putstr_fd("rr", 1);
		ft_putchar_fd(stack->name, 1);
		ft_putchar_fd('\n', 1);
	}
}
