/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kilfen_baridon.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 09:33:13 by Camille           #+#    #+#             */
/*   Updated: 2026/01/08 16:04:23 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm_kilfen_baridon(t_stack *a, t_stack *b)
{
	t_chunk	**chunks;

	chunks = calculate_chunks(a);
	// PHASE 1:
	// tant que il ne reste pas 3 nb dans la stack a
			// if nba appartient aux deux plus petit chunks a traiter : push b
			// if nba appartient aux bigest chunk restants
			//			if nbb est parmis le plus petit chunk restant
			//				rr
			//			else
			//				ra
			//	else if nbb est parmis le plus petit chunk restant
			//		rb
	// sort_3 stack a
	
	// PHASE 2:
	
	// PHASE 3:
	free_chunk(chunks, STACK_SHARE);
}
