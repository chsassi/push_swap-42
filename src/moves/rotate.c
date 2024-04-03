/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:46:10 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/02 20:46:13 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dll	*rotate_moves(t_dll *node1)
{
	t_dll	*tmp;

	tmp = node1->next;
	dll_add_back(&tmp, node1);
	tmp->prev = NULL;
	node1 = tmp;
	return (node1);
}

t_dll	*rr(t_dll *stack_a, t_dll **stack_b, int flag)
{
	t_dll	*stack_res;

	if (flag == MOVE_A)
	{
		stack_res= rotate_moves(stack_a);
		return (write(1, "ra\n", 3), stack_res);
	}
	else if (flag == MOVE_B)
	{
		stack_res = rotate_moves(*stack_b);
		return (write(1, "rb\n", 3), stack_res);
	}
	else if (flag == MOVE_BOTH)
	{
		stack_a = rotate_moves(stack_a);
		*stack_b = rotate_moves(*stack_b);
	}
	return (write(1, "rr\n", 3), stack_a);
}
