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
	dll_add_front(&stack_a, (*stack_b));
	(*stack_b)->next->prev = NULL;
	*stack_b = (*stack_b)->next;
	return ();
}

t_dll	*pb(t_dll *stack_a, t_dll **stack_b)
{

}