/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:03:34 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/09 15:46:46 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dll	*solve_3(t_dll *pStack)
{
	if (pStack->value > pStack->next->value)
	{
		if (pStack->next->value > pStack->next->next->value)
		{
			rotate(pStack, NULL, MOVE_A);
			swap(pStack, NULL, MOVE_A);
		}
		else
			rotate(pStack, NULL, MOVE_A);
	}
	else if (pStack->value < pStack->next->value)
	{
		if (pStack->value < pStack->next->next->value)
		{
			swap(pStack, NULL, MOVE_A);
			rotate(pStack, NULL, MOVE_A);
		}
		else
			r_rotate(pStack, NULL, MOVE_A);
	}
	return (pStack);
}

t_dll	*solve_4(t_dll *pStack)
{
	t_dll	*tmp;
	t_dll	*stack_b;
	int		i;

	stack_b = (t_dll *){0};
	tmp = dll_last(pStack);
	i = find_min(pStack);
	if (i > 1)
	{
		i = 4 - i;
		while (i > 0)
		{
			r_rotate(pStack, NULL, MOVE_A);
			i--;
		}
	}
	else
	{
		while (i <= 0)
		{
			rotate(pStack, NULL, MOVE_A);
			i++;
		}
	}
	pb(stack_b, &pStack);
	pStack = solve_3(pStack);
	pa(pStack, &stack_b);
	return (pStack);
}

t_dll	*solve_5(t_dll *pStack)
{
	t_dll	*tmp;
	t_dll	*stack_b;
	int		i;

	i = find_min(pStack);
	tmp = dll_last(pStack);
	stack_b = (t_dll *){0};
	if (i > 2)
	{
		i = 5 - i;
		while (i > 0)
		{
			r_rotate(pStack, NULL, MOVE_A);
			i--;
		}
	}
	else
	{
		while (i <= 0)
		{
			rotate(pStack, NULL, MOVE_A);
			i++;
		}
	}
	pb(stack_b, &pStack);
	pStack = solve_4(pStack);
	pa(pStack, &stack_b);
	return (pStack);
}
