/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:59:28 by Camille           #+#    #+#             */
/*   Updated: 2025/12/23 12:10:08 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "ft_ctype.h"
# include "ft_stdio.h"
# include "ft_stdlib.h"

# ifndef STACK_SHARE
#  define STACK_SHARE 3
# endif

typedef struct s_stack
{
	int				nb;
	int				rank;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_positions
{
	int				i;
	struct s_stack	*head;
	struct s_stack	*tail;
}	t_positions;

// push_swap.c
void	trigger_error(t_stack **stack);

// stack.c
t_stack	*stack_new(int nb);
bool	stack_add(int nb, t_stack **current, t_positions *pos);

// positions.c
void	set_positions(t_positions *pos, int i, t_stack *head, t_stack *tail);

#endif
