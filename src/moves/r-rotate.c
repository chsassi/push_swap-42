/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r-rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:46:10 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/02 20:46:13 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dll	*rev_rotate_moves(t_dll *node1)
{
	t_dll	*tmp;

	tmp = dll_last(node1);
	dll_add_back(&node1, tmp);
	return (node1);
}

t_dll	*rrr(t_dll *stack_a, t_dll **stack_b, int flag)
{
	t_dll	*stack_res;

	if (flag == MOVE_A)
	{
		stack_res= rev_rotate_moves(stack_a);
		return (write(1, "rra\n", 4), stack_res);
	}
	else if (flag == MOVE_B)
	{
		stack_res = rev_rotate_moves(*stack_b);
		return (write(1, "rrb\n", 4), stack_res);
	}
	else if (flag == MOVE_BOTH)
	{
		stack_a = rev_rotate_moves(stack_a);
		*stack_b = rev_rotate_moves(*stack_b);
	}
	return (write(1, "rrr\n", 4), stack_a);
}
