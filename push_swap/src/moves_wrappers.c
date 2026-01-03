/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_wrappers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:04:57 by Camille           #+#    #+#             */
/*   Updated: 2026/01/03 17:05:26 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	swap(a, false);
	swap(b, false);
	ft_putchar_fd('\n', 1);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a, false);
	rotate(b, false);
	ft_putchar_fd('\n', 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a, false);
	reverse_rotate(b, false);
	ft_putstr_fd("rrr\n", 1);
}
