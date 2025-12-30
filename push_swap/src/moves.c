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

void	swap(t_stack *stack)
{
	int	nb;

	nb = stack->nb;
	stack->nb = stack->next->nb;
	stack->next->nb = nb;
}

void	rotate(t_stack **stack, t_positions *pos)
{
	pos->head = pos->head->next;
	pos->tail = pos->head->prev;
	(*stack) = pos->head;
	(*stack)->prev = pos->tail;
	(*stack)->next = pos->head->next;
}
