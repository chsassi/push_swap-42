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
	MOVE_A,
	MOVE_B,
	MOVE_BOTH,
	PUSH,
	ROTATE,
	R_ROTATE,
	SWAP
}	t_moves;

/* Algo */

t_dll	*solve_3(t_dll *pStack);
t_dll	*solve_4(t_dll *pStack);
int		check_5(t_dll *pStack);
void	solve_5(t_dll *pStack);

/* Parsing */

t_dll	*get_list_head(char **mtx);
t_dll	*parse_input_string(int ac, char **av);
t_dll	*parse_input_args(int ac, char **av);

/* Utils */

int		check_duplicates(char **mtx);
int		find_min(t_dll *pStack);
int		is_sorted(t_dll *pStack);
int		mtx_check(char **mtx);

/* Moves */

t_dll	*swap_op(t_dll *node1);
t_dll	*swap(t_dll *stack_a, t_dll **stack_b, int flag);

t_dll	*rotate_op(t_dll *node1);
t_dll	*rotate(t_dll *stack_a, t_dll **stack_b, int flag);

t_dll	*r_rotate_op(t_dll *node1);
t_dll	*r_rotate(t_dll *stack_a, t_dll **stack_b, int flag);

t_dll	*pa(t_dll *stack_a, t_dll **stack_b);
t_dll	*pb(t_dll *stack_b, t_dll **stack_a);

#endif