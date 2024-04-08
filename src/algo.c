/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:03:34 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/05 18:03:36 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check5(t_dll *list)
{
	t_dll	*tmp;

	tmp = dll_last(list);
	if (list->value > list->next->value && list->value > tmp->value)
	{
		if (list->next->value > tmp->value)
			return (SWAP);
		else
			return (REV_ROTATE);
	}
	else if (list->value > list->next->value && list->value < tmp->value)
		return (ROTATE);
	else if (list->value < list->next->value && list->value > tmp->value)
		return (SWAP);
	else if (list->value < list->next->value && list->value < tmp->value)
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
	// check5();
}