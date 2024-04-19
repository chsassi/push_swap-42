/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:46:10 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/02 20:46:13 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dll	*pa(t_dll *stack_a, t_dll **stack_b)
{
	t_dll	tmp;

	tmp = **stack_b;
	dll_add_front(&stack_a, &tmp);
	(*stack_b) = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	write(1, "pb\n", 3);
	return (stack_a);
}

t_dll	*pb(t_dll *stack_b, t_dll **stack_a)
{
	t_dll	tmp;

	tmp = **stack_a;
	dll_add_front(&stack_b, &tmp);
	(*stack_a) = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	write(1, "pb\n", 3);
	return (stack_b);
}
