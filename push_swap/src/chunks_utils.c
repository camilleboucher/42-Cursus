/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:13:57 by Camille           #+#    #+#             */
/*   Updated: 2026/01/11 18:44:29 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_smallest_available_chunk(t_chunk **chunks)
{
	int	i;

	i = 0;
	while (i != STACK_SHARE)
	{
		if (!chunks[i]->completed)
			return (i);
		i++;
	}
	return (STACK_SHARE);
}

bool	in_first_available_chunk_or_the_next(t_chunk **chunks, int rank)
{
	int	i;

	i = first_smallest_available_chunk(chunks);
	if (rank >= chunks[i]->min && rank <= chunks[i]->max)
		return (true);
	i++;
	if (i != STACK_SHARE && rank >= chunks[i]->min && rank <= chunks[i]->max)
		return (true);
	return (false);
}

bool	in_smallest_available_chunk(t_chunk **chunks, int rank)
{
	int	i;

	i = first_smallest_available_chunk(chunks);
	if (rank >= chunks[i]->min && rank <= chunks[i]->max)
		return (true);
	return (false);
}

bool	find_rotation_and_optimize(t_chunk **chunks, t_stack *b, int rank)
{
	if (in_smallest_available_chunk(chunks, rank)
		&& first_smallest_available_chunk(chunks) != STACK_SHARE - 1
		&& !in_smallest_available_chunk(chunks, b->head->next->rank))
		return (true);
	return (false);
}
