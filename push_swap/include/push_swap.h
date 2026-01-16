/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:59:28 by Camille           #+#    #+#             */
/*   Updated: 2026/01/16 11:53:42 by Camille          ###   ########.fr       */
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

typedef struct s_node
{
	int				nb;
	int				rank;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	char	name;
	int		nodes_count;
	t_node	*head;
	t_node	*tail;
	t_node	*current;
}	t_stack;

// push_swap.c
int		main(int argc, char **argv);
void	trigger_error(t_stack *stack);

// stack.c
bool	init_stack_a(int nb, t_stack *stack);
bool	has_duplicate(int nb, t_stack *a);
bool	add_node(int nb, t_stack *stack);
void	free_stack(t_stack *stack);
void	print_stack(t_stack *stack);

// stack_utils.c
bool	is_sorted(t_stack *stack);
t_node	*find_smallest_nb(t_stack *stack);
t_node	*find_first_nb_bigger_than(t_stack *sorted_stack, int nb);
void	positionning_head(t_stack *stack, t_node *to);

// main_logic.c
void	main_logic(t_stack *a, t_stack *b);
void	rank(t_stack *a);
t_node	*find_next_smallest_nb(t_stack *stack, t_node **save_in);

// moves.c
void	swap(t_stack *stack, bool display_stackname);
void	rotate(t_stack *stack, bool display_stackname);
void	reverse_rotate(t_stack *stack, bool display_stackname);
void	push(t_stack *from, t_stack *to);

// moves_wrappers.c
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// algorithm/jamie_dawson.c
void	sort_3(t_stack *s);
void	sort_456(t_stack *a, t_stack *b);

// algorithm/butterfly.c
void	algorithm_butterfly(t_stack *a, t_stack *b);
void	phase_1(t_stack *a, t_stack *b);
void	phase_2(t_stack *a, t_stack *b);
int		count_until_bigest_rank(t_stack *b);

#endif
