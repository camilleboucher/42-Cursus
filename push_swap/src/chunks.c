/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:50:21 by Camille           #+#    #+#             */
/*   Updated: 2026/01/12 17:00:27 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include <stdlib.h>

void	calculate_chunks(t_stack *a, t_chunk **chunks)
{
	float	range_chunk;
	int		i;

	i = 0;
	range_chunk = (float)a->nodes_count / STACK_SHARE;
	if (range_chunk - (int)range_chunk < 0.5)
		range_chunk = (int)range_chunk;
	else
		range_chunk = (int)range_chunk + 1;
	while (i != STACK_SHARE)
	{
		chunks[i] = malloc(sizeof(t_chunk));
		if (!chunks[i])
			error_chunks(a, chunks, i + 1);
		if (i + 1 == STACK_SHARE)
			chunks[i]->max = a->nodes_count;
		else
			chunks[i]->max = range_chunk * (i + 1);
		if (i)
			chunks[i]->min = chunks[i - 1]->max + 1;
		chunks[i]->nodes_count = 0;
		chunks[i]->completed = false;
		i++;
	}
	chunks[0]->min = 1;
}

void	init(t_chunk **chunks)
{
	int	i;

	i = 0;
	while (i != STACK_SHARE)
	{
		chunks[i]->nodes_count = 0;
		chunks[i]->completed = false;
		i++;
	}
}

void	update(t_chunk **chunks, int rank)
{
	int	i;

	i = 0;
	while (i != STACK_SHARE)
	{
		if (rank >= chunks[i]->min && rank <= chunks[i]->max)
		{
			chunks[i]->nodes_count++;
			break ;
		}
		i++;
	}
	if (chunks[i]->nodes_count == chunks[i]->max - chunks[i]->min + 1)
		chunks[i]->completed = true;
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
