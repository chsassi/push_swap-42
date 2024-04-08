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
	REV_ROTATE,
	SWAP
}	t_moves;


/* Parsing */

t_dll	*get_list(char **mtx);
t_dll	*parse_input_string(int ac, char **av);
t_dll	*parse_input_args(int ac, char **av);
int		check_duplicates(char **mtx);
int		is_sorted(t_dll *list);
int		mtx_check(char **mtx);

/* Algo */

int	check5(t_dll *list);
void	solve5(t_dll *list);

/* Moves */

t_dll	*swap_moves(t_dll *node1);
t_dll	*ss(t_dll *stack_a, t_dll **stack_b, int flag);

t_dll	*rotate_moves(t_dll *node1);
t_dll	*rr(t_dll *stack_a, t_dll **stack_b, int flag);

t_dll	*rev_rotate_moves(t_dll *node1);
t_dll	*rrr(t_dll *stack_a, t_dll **stack_b, int flag);

t_dll	*pa(t_dll *stack_a, t_dll **stack_b);
t_dll	*pb(t_dll *stack_b, t_dll **stack_a);

# endif
