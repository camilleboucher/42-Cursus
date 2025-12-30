/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:59:28 by Camille           #+#    #+#             */
/*   Updated: 2025/12/30 09:54:24 by Camille          ###   ########.fr       */
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
	int				count;
	struct s_stack	*head;
	struct s_stack	*tail;
	struct s_stack	*current;
}	t_positions;

// push_swap.c
void	trigger_error(t_positions *pos);

// stack.c
t_stack	*stack_new(int nb);
bool	stack_add(int nb, t_positions *pos);
bool	hasDuplicates(int nb, t_stack *a);
void	freeStack(t_positions *pos);
void	printStack(t_stack *a, t_positions *pos);

// positions.c
void	init_positions(t_positions *pos, int i, t_stack *stack);

// algorithm/kilfen_baridon.c


#endif
