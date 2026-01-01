/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:10:48 by Camille           #+#    #+#             */
/*   Updated: 2026/01/01 12:08:24 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	add_node(int nb, t_stack *stack)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (false);
	stack->tail->next = node;
	node->nb = nb;
	node->prev = stack->tail;
	node->next = stack->head;
	stack->tail = node;
	return (true);
}
