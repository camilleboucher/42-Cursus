/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:10:48 by Camille           #+#    #+#             */
/*   Updated: 2025/12/23 11:09:38 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_positions(t_positions *pos, int i, t_stack *head, t_stack *tail)
{
	pos->i = i;
	pos->head = head;
	pos->tail = tail;
}
