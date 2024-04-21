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
	if (!(is_sorted(pStack)) && pStack->value > pStack->next->value)
	{
		if (pStack->next->value > pStack->next->next->value)
		{
			pStack = rotate(pStack, NULL, MOVE_A);
			pStack = swap(pStack, NULL, MOVE_A);
		}
		else
			pStack = rotate(pStack, NULL, MOVE_A);
	}
	else if (!(is_sorted(pStack)) && pStack->value < pStack->next->value)
	{
		if (pStack->value < pStack->next->next->value)
		{
			pStack = swap(pStack, NULL, MOVE_A);
			pStack = rotate(pStack, NULL, MOVE_A);
		}
		else
			pStack = r_rotate(pStack, NULL, MOVE_A);
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
	i = find_min_index(pStack);
	if (i > 1)
	{
		i = 4 - i;
		while (i > 0)
		{
			pStack = r_rotate(pStack, NULL, MOVE_A);
			i--;
		}
	}
	else
	{
		while (i <= 0)
		{
			pStack = rotate(pStack, NULL, MOVE_A);
			i++;
		}
	}
	if (is_sorted(pStack))
		return (pStack);
	stack_b = pb(stack_b, &pStack);
	pStack = solve_3(pStack);
	pStack = pa(pStack, &stack_b);
	return (pStack);
}

t_dll	*solve_5(t_dll *pStack)
{
	t_dll	*tmp;
	t_dll	*stack_b;
	int		i;

	i = find_min_index(pStack);
	tmp = dll_last(pStack);
	stack_b = (t_dll *){0};
	if (i > 2)
	{
		i = 5 - i;
		while (i > 0)
		{
			pStack = r_rotate(pStack, NULL, MOVE_A);
			i--;
		}
	}
	else
	{
		while (i <= 0)
		{
			pStack = rotate(pStack, NULL, MOVE_A);
			i++;
		}
	}
	pStack = pb(stack_b, &pStack);
	pStack = solve_4(pStack);
	pStack = pa(pStack, &stack_b);
	return (pStack);
}
