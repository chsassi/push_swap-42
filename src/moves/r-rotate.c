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

t_dll	*r_rotate_op(t_dll *node1)
{
	t_dll	*tmp;

	tmp = dll_last(node1);
	tmp->next = node1;
	tmp->prev = NULL;
	node1 = tmp;
	return (node1);
}

t_dll	*r_rotate(t_dll *stack_a, t_dll **stack_b, int flag)
{
	t_dll	*stack_res;

	if (flag == MOVE_A)
	{
		stack_res = r_rotate_op(stack_a);
		return (write(1, "rra\n", 4), stack_res);
	}
	else if (flag == MOVE_B)
	{
		stack_res = r_rotate_op(*stack_b);
		return (write(1, "rrb\n", 4), stack_res);
	}
	else if (flag == MOVE_BOTH)
	{
		stack_a = r_rotate_op(stack_a);
		*stack_b = r_rotate_op(*stack_b);
		return (write(1, "rrr\n", 4), stack_a);
	}
	return (0);
}
