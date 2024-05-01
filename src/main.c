/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <chsassi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:16:28 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/28 18:01:50 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_dll	*stack_a;
	t_dll	*stack_b;
	int		len;

	stack_a = init_stack(ac, av);
	stack_b = NULL;
	len = dll_size(stack_a);
	if (len <= 5)
		minisort(&stack_a, &stack_b);
	else
	{
		stack_b = get_stack_lis(&stack_a);
		if (!stack_b)
			return (0);
		sort_all(&stack_a, &stack_b);
	}
	dll_clear(&stack_a);
	return (0);
}
