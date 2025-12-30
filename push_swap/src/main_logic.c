/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 10:13:37 by Camille           #+#    #+#             */
/*   Updated: 2025/12/30 11:43:48 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// INFO: BESOIN de pos desormais ? a voir au futur
void	main_logic(t_stack *a, t_positions *pos)
{
	printStack(a, pos);
	//swap(a);
	//rotate(&a, pos);
	printStack(a, pos);
}
