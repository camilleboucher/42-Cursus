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
	//print_stack(a);
	if (a->nodes_count == 2 && a->head->nb > a->tail->nb)
		swap(a, true);
	else if (a->nodes_count == 3)
		sort_3(a);
	else if (a->nodes_count >= 4 && a->nodes_count <= 6)
		sort_456(a, b); //TODO: generer des nb aleatoires et/ou utiliser des testers
	else
	{
		rank(a);
		algorithm_kilfen_baridon(a, b);
	}
	//print_stack(a);
	//print_stack(b);




	//(void)b;
	//ft_printf("%d", a->nodes_count);
	//print_stack(a);
	//swap(a, true);
	//rotate(a, true);
	//reverse_rotate(a, true);
	/*print_stack(a);
	push(a, b);
	push(a, b);
	push(a, b);
	push(a, b);*/
	/*push(a, b);
	push(a, b);
	*/
	/*print_stack(a);
	print_stack(b);
	push(b, a);
	push(b, a);
	push(b, a);
	push(b, a);
	push(b, a);
	ft_printf("\n");
	print_stack(a);
	print_stack(b);
	ft_printf("%p", b->head);
	push(b, a);
	print_stack(b);
	ft_printf("%p", b->head);
	*//*push(b, a);
	push(b,a);
	push(b,a);
	push(b,a);
	print_stack(a);
	push(a,b);
	push(a,b);*/
	/*rr(a, b);
	rrr(a, b);
	ss(a, b);
	swap(a, true);
	print_stack(a);
	print_stack(b);*/
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
