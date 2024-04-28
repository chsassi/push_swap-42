/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:03:34 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/28 18:01:50 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_move(t_dll *stack_a)
{
	int		head_value;
	int		middle_value;
	int		last_value;
	int		min_value;
	int		max_value;

	head_value = stack_a->value;
	middle_value = stack_a->next->value;
	last_value = stack_a->next->next->value;
	min_value = find_min_value(stack_a);
	max_value = find_max_value(stack_a);
	if ((middle_value == max_value && head_value == min_value)
		|| (middle_value == min_value && last_value == max_value)
		|| (middle_value != min_value && middle_value != max_value))
		return (SWAP);
	if (middle_value == min_value && head_value == max_value)
		return (ROTATE);
	else if (middle_value == max_value && last_value == min_value)
		return (R_ROTATE);
	return (STAY);
}

void	sort_3(t_dll **stack_a)
{
	if (!stack_a || !(*stack_a))
		return ;
	if (is_sorted(*stack_a))
		return ;
	if (find_move(*stack_a) == SWAP)
		swap(stack_a, NULL, MOVE_A);
	if (find_move(*stack_a) == ROTATE)
		rotate(stack_a, NULL, MOVE_A);
	else if (find_move(*stack_a) == R_ROTATE)
		r_rotate(stack_a, NULL, MOVE_A);
}

void	sort_4(t_dll **stack_a, t_dll **stack_b)
{
	int		i;

	i = find_min_index(*stack_a);
	if (i >= 1)
	{
		i = 4 - i;
		while (i > 0)
		{
			r_rotate(stack_a, NULL, MOVE_A);
			i--;
		}
	}
	else if (i > 0)
	{
		while (i < 1)
		{
			rotate(stack_a, NULL, MOVE_A);
			i++;
		}
	}
	if (is_sorted(*stack_a))
		return ;
	pb(stack_b, stack_a);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_dll **stack_a, t_dll **stack_b)
{
	int		i;

	i = find_min_index(*stack_a);
	if (i >= 2)
	{
		i = 5 - i;
		while (i > 0)
		{
			r_rotate(stack_a, NULL, MOVE_A);
			i--;
		}
	}
	else if (i > 0)
	{
		while (i < 2)
		{
			rotate(stack_a, NULL, MOVE_A);
			i++;
		}
	}
	pb(stack_b, stack_a);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	minisort(t_dll **stack_a, t_dll **stack_b)
{
	int		len;

	len = dll_size(*stack_a);
	if (len == 2 && (*stack_a)->value > (*stack_a)->next->value)
		swap(stack_a, NULL, MOVE_A);
	else if (len == 3)
		sort_3(stack_a);
	else if (len == 4)
		sort_4(stack_a, stack_b);
	else if (len == 5)
		sort_5(stack_a, stack_b);
}
