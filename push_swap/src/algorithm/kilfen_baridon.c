/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kilfen_baridon.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 09:33:13 by Camille           #+#    #+#             */
/*   Updated: 2026/01/12 17:02:54 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// PHASE 1 :
// =========
//	rank = 0
//	TANT QUE il ne reste pas 3 nodes dans stack A
//			SI rank tete A N'EST PAS compris dans le dernier chunk dispo ou le suivant
//					ROTATE A
//			SINON
//					PUSH B
//					SI il y a plus d'une node dans B
//							rank = rank de tete de B (sauvegarde pour plus tard si rotations)
//					SI rank EST DANS le plus petit chunk dispo (false si 0)
//					ET SI le dernier chunk dispo n'est pas le dernier
//					ET SI le prochain rank de B n'est pas dans le dernier chunk dispo
//							SI rank tete A N'EST PAS dans le dernier chunk dispo ou le suivant
//									RR (ROTATE AB)
//							SINON
//									ROTATE B
//							SI rank n'est pas valide (rank = 0)
//									rank = rank de tete de B
//							UPDATE chunks en fonction du rank trie
//	SORT_3 stack A
//	INFO: Optimisation possible en comparant si il reste un seul chunk vide :
//	le trier sur lui meme

// PHASE 2 :
// =========
//	rank_to_sort = chunks[STACK_SHARE - 1]->max;
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
//
//

// PHASE 3 :
// =========
void	algorithm_kilfen_baridon(t_stack *a, t_stack *b)
{
	t_chunk	**chunks;

	chunks = malloc(sizeof(t_chunk *) * STACK_SHARE);
	if (!chunks)
		trigger_error(a);
	calculate_chunks(a, chunks);
	phase_1(a, b, chunks);
	init(chunks);
	chunks[STACK_SHARE - 1]->nodes_count = 3;
	phase_2(a, b, chunks);

	/*
	// IMPRIMER CHUNKS decoupage
	// =========================
	int i = 0;
	while (i != STACK_SHARE)
	{
		ft_printf("chunk %d | min : %d | max : %d\n", i, chunks[i]->min, chunks[i]->max);
		i++;
	}
	*/
	free_chunk(chunks, STACK_SHARE);
}

void	phase_1(t_stack *a, t_stack *b, t_chunk **chunks)
{
	int	rank;

	rank = 0;
	while (a->nodes_count != 3)
	{
		if (!in_first_available_chunk_or_the_next(chunks, a->head->rank))
			rotate(a, true);
		else
		{
			push(a, b);
			if (b->nodes_count > 1)
				rank = b->head->rank;
			if (find_rotation_and_optimize(chunks, b, rank))
			{
				if (!in_first_available_chunk_or_the_next(chunks, a->head->rank))
					rr(a, b);
				else
					rotate(b, true);
			}
			if (!rank)
				rank = b->head->rank;
			update(chunks, rank);
		}
	}
	sort_3(a);
}

void	phase_2(t_stack *a, t_stack *b, t_chunk **chunks)
{
	(void)a;
	(void)b;
	(void)chunks;
}
