/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:46:42 by chsassi           #+#    #+#             */
/*   Updated: 2024/05/01 17:46:44 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_swap_op(t_dll **stack_a)
{
	t_dll	*head;
	int		tmp_value;

	if (dll_size(*stack_a) == 1)
		return ;
	head = *stack_a;
	tmp_value = head->value;
	head->value = head->next->value;
	head->next->value = tmp_value;
}

void	checker_swap(t_dll **stack_a, t_dll **stack_b, int flag)
{
	if (flag == MOVE_A)
		checker_swap_op(stack_a);
	else if (flag == MOVE_B)
		checker_swap_op(stack_b);
	else if (flag == MOVE_BOTH)
	{
		checker_swap_op(stack_a);
		checker_swap_op(stack_b);
	}
}
