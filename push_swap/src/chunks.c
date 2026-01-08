/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:50:21 by Camille           #+#    #+#             */
/*   Updated: 2026/01/08 15:37:19 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_chunk	**calculate_chunks(t_stack *a)
{
	t_chunk	**chunks;
	int		range_chunk;
	int		i;

	chunks = malloc(sizeof(t_chunk *) * STACK_SHARE);
	if (!chunks)
		trigger_error(a);
	i = 0;
	range_chunk = a->nodes_count / STACK_SHARE;
	while (i != STACK_SHARE)
	{
		chunks[i] = malloc(sizeof(t_chunk));
		if (!chunks[i])
			error_chunks(a, chunks, i + 1);
		if (i + 1 == STACK_SHARE)
			chunks[i]->max = a->nodes_count;
		else
			chunks[i]->max = range_chunk * (i + 1);
		chunks[i]->min = chunks[i]->max - range_chunk + 1;
		chunks[i]->nodes_count = 0;
		chunks[i]->complete = false; //INFO: pertinent ?
		i++;
	}
	return (chunks);
}

void	error_chunks(t_stack *a, t_chunk **chunks, int nb_chunks)
{
	free_stack(a);
	free_chunk(chunks, nb_chunks);
	exit(1);
}

void	free_chunk(t_chunk **chunks, int nb_chunks)
{
	while (nb_chunks)
	{
		nb_chunks--;
		free(chunks[nb_chunks]);
	}
	free(chunks);
}
