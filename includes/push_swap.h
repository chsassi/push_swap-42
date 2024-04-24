/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:50:39 by chsassi           #+#    #+#             */
/*   Updated: 2024/03/30 15:50:41 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef enum e_moves
{
	STAY,
	MOVE_A,
	MOVE_B,
	MOVE_BOTH,
	PUSH,
	ROTATE,
	R_ROTATE,
	SWAP
}	t_moves;

/* Minisort */

int		find_move(t_dll *pStack);
t_dll	**sort_3(t_dll **pStack);
t_dll	**sort_4(t_dll **pStack, t_dll **stack_b);
t_dll	**sort_5(t_dll **pStack, t_dll **stack_b);
void	minisort(t_dll *pStack);

/* Parsing */

t_dll	*set_list_head(char **mtx);
t_dll	*parse_input_string(int ac, char **av);
t_dll	*parse_input_arguments(int ac, char **av);
t_dll	*init_stack(int ac, char **av);

/* Utils */

int		check_duplicates(char **mtx);
int		is_sorted(t_dll *pStack);
int		mtx_check(char **mtx);
void	print_stack(t_dll *pNode);

/* Moves */

t_dll	**swap_op(t_dll **node1);
t_dll	**swap(t_dll **stack_a, t_dll **stack_b, int flag);

t_dll	**rotate_op(t_dll **stack);
t_dll	**rotate(t_dll **stack_a, t_dll **stack_b, int flag);

t_dll	**r_rotate_op(t_dll **stack);
t_dll	**r_rotate(t_dll **stack_a, t_dll **stack_b, int flag);

void	pa(t_dll **stack_a, t_dll **stack_b);
void	pb(t_dll **stack_b, t_dll **stack_a);

#endif