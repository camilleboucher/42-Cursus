/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jamie_dawson.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 09:33:13 by Camille           #+#    #+#             */
/*   Updated: 2026/01/06 15:11:22 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *s)
{
	int	head;
	int	middle;
	int	tail;

	head = s->head->nb;
	middle = s->head->next->nb;
	tail = s->tail->nb;
	if (head > middle && middle < tail && tail > head)
		swap(s, true);
	else if (head > middle && middle > tail && tail < head)
	{
		swap(s, true);
		reverse_rotate(s, true);
	}
	else if (head > middle && middle < tail && tail < head)
		rotate(s, true);
	else if (head < middle && middle > tail && tail > head)
	{
		swap(s, true);
		rotate(s, true);
	}
	else if (head < middle && middle > tail && tail < head)
		reverse_rotate(s, true);
}

void	sort_456(t_stack *a, t_stack *b)
{
	int	nb_push;
	int	i;

	if (is_sorted(a))
		return ;
	nb_push = a->nodes_count - 3;
	i = nb_push;
	while (i--)
		push(a, b);
	sort_3(a);
	i = nb_push;
	while (i--)
	{
		positionning_head(a, find_first_nb_bigger_than(a, b->head->nb));
		push(b, a);
	}
	positionning_head(a, find_smallest_nb(a));
}
