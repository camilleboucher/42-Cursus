/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_utils_phase_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:55:42 by Camille           #+#    #+#             */
/*   Updated: 2026/01/12 16:56:09 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//FIX: RELIRE LA VIDEO YOUTUBE car je dois pour chaque nb du bon chunk calculer
//les 4 moves a utiliser : ra+rb (rr), ra+rrb, rra+rb, rra+rrb (rrr)

// PHASE 2 :
// =========
//	rank_to_sort = b->nodes_count + 3;
//	TANT QUE tous les chunks ne sont pas complet
//			i = STACK_SHARE - 1; (index du chunk a traiter)
//			TANT QUE chunks[i] n'est pas complet
//					trouver le B a push le plus proche qui peut se mettre en dessous du triage
//					ET au dessus du buffer (le buffer se trouve en dessous du triage (donc du bigest_rank))
//					(tant que le bigest_rank n'est pas trie, la stack a est forcement le buffer de tri)

void	push_phase_2(t_stack *a, t_stack *b, int b_rotations, int a_rotations)
{
	void	(*rotation_of_b)(t_stack *, bool);
	void	(*rotation_of_a)(t_stack *, bool);
	int		i;

	rotation_of_b = rotate;
	if (b_rotations < 0)
	{
		rotation_of_b = reverse_rotate;
		b_rotations *= -1;
	}
	rotation_of_a = rotate;
	if (a_rotations < 0)
	{
		rotation_of_a = reverse_rotate;
		a_rotations *= -1;
	}
	if (rotation_of_b == rotation_of_a)
	{
		i = b_rotations - a_rotations
	}
		

	//rotate a que si c'est pas celui a ranger qui est push
	//reverse rotate a n fois que si la tail correspond a celui a ranger et n + 1...
}

	// le b a trouver doit appartir au plus gros chunk dispo
	// ET (tail == bigest_rank OU (b < tete A OU b > tail A))
int	calculate_rotations_of_b(t_stack *a, t_stack *b,
							 t_chunk **chunks, t_references ref)
{
	ref.i_rotate = 0;
	b->current = b->head;
	while (!(in_bigest_available_chunk(chunks, b->current->rank)
		&& (a->tail->rank == ref.bigest_rank ||
		(b->current->rank < a->head->rank || b->current->rank > a->tail->rank))))
	{
		ref.i_rotate++;
		b->current = b->current->next;
	}
	ref.i_reverse_rotate = 0;
	b->current = b->tail;
	while (!(in_bigest_available_chunk(chunks, b->current->rank)
		&& (a->tail->rank == ref.bigest_rank ||
		(b->current->rank < a->head->rank || b->current->rank > a->tail->rank))))
	{
		ref.i_reverse_rotate++;
		b->current = b->current->prev;
	}
	if (ref.i_rotate <= ref.i_reverse_rotate)
		return (ref.i_rotate);
	return (ref.i_reverse_rotate * -1);
}

bool	in_bigest_available_chunk(t_chunk **chunks, int rank)
{
	int	i;

	i = STACK_SHARE - 1;
	while (i > -1)
	{
		if (!chunks[i]->completed)
		{
			if (rank >= chunks[i]->min && rank <= chunks[i]->max)
				return (true);
			else
				return (false);
		}
		i--;
	}
	return (false);
}

/*
// PHASE 2 :
// =========
//	rank_to_sort = b->nodes_count + 3;
//	TANT QUE tous les chunks ne sont pas complet
//			i = STACK_SHARE - 1; (index du chunk a traiter)
//			TANT QUE chunks[i] n'est pas complet
//					SI je peux mettre head A apres tail A
//					(head dois etre plus grand que tail OU tail est le bigest alltime)
//							CALCULER le nb de rotation de A necessaire et voir si
//							le prochain push de B peut accumuler ces rotations ci
//							ROTATIONS de A et potentiellement certains B en meme temps
//					SINON SI je peux mettre tail A a head A (si c'est le rank avant
//					le dernier deja trie)
//							CALCULER le nb de rotation de A necessaire et voir si
//							le prochain push de B peut accumuler ces rotations ci
//							ROTATIONS de A et potentiellement certains B en meme temps
//							UPDATE chunk et rank to sort si le rank to sort est trie
//					SINON (je ne peux pas odonner stack A)
//							je cherche le prochain node B a push qui :
//							coute le moins de rotation de B et de A avant le push
//							"FUSION" des rotations dans le meme sens (B et A avant le push)
//							ROTATIONS de A et/ou B avant de PUSH
//							PUSH A

int	times_can_put_head_after_tail(t_stack *a, t_references ref)
{
	t_node	*head;
	t_node	*tail;

	head = a->head;
	tail = a->tail;
	ref.i = 0;
	while (1)
	{
		if (head->rank <= ref.rank_to_sort
			&& (head->rank > tail->rank || tail->rank == ref.bigest_rank))
			continue ;
		else
			break ;
		ref.i++;
		tail = head;
		head = head->next;
	}
	return (ref.i);
}

int	times_can_put_tail_after_head(t_stack *a, t_references ref)
{
	t_node	*head;
	t_node	*tail;

	head = a->head;
	tail = a->tail;
	ref.i = 0;
	while (1)
	{
		if (tail->rank == ref.rank_to_sort
		&& (head->rank == ref.rank_to_sort + 1 || tail->rank == ref.bigest_rank))
			continue ;
		else
			break ;
		ref.i++;
		head = tail;
		tail = tail->prev;
		ref.rank_to_sort--;
	}
	return (ref.i);
}

int	calculate_rotations_of_b(t_stack *a, t_stack *b, t_chunk **chunks,
							 t_references ref)
{
	if (r
}*/

