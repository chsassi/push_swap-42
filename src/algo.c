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

int	solve3(t_dll *pStack)
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
			rev_rotate(pStack, NULL, MOVE_A);
	}
	return (0);
}

int	solve4(t_dll *pStack_a, t_dll *pStack_b)
{
	t_dll	*tmp;

	tmp = dll_last(pStack_a);
	find_min(pStack_a);
	if (pStack_a->value > pStack_a->next->value && pStack_a->value > tmp->value)
	{
		if (pStack_a->next->value > pStack_a->next->next->value)
		{
			rotate(pStack_a, NULL, MOVE_A);
			swap(pStack_a, NULL, MOVE_A);
		}
		else
			rotate(pStack_a, NULL, MOVE_A);
	}
	else if (pStack_a->value < pStack_a->next->value && pStack_a->value > tmp->value)
	{
		if (pStack_a->next->value > pStack_a->next->next->value)
		{
			ss(pStack_a, NULL, MOVE_A);
			rr(pStack_a, NULL, MOVE_A);
		}
		else
			rrr(pStack_a, NULL, MOVE_A);
	}
	return (0);
}

int	check5(t_dll *pStack)
{
	t_dll	*tmp;

	tmp = dll_last(pStack);
	if (pStack->value > pStack->next->value && pStack->value > tmp->value)
	{
		if (pStack->next->value > tmp->value)
			return (SWAP);
		else
			return (REV_ROTATE);
	}
	else if (pStack->value > pStack->next->value && pStack->value < tmp->value)
		return (ROTATE);
	else if (pStack->value < pStack->next->value && pStack->value > tmp->value)
		return (SWAP);
	else if (pStack->value < pStack->next->value && pStack->value < tmp->value)
		return (PUSH);
	return (0);
}

void	solve5(t_dll *list)
{
	t_dll	*stack_a;
	t_dll	*stack_b;

	stack_a = dll_last(list);
	stack_b = NULL;
	if (!stack_a || !stack_b)
		return ;
}
