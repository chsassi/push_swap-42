/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:46:07 by chsassi           #+#    #+#             */
/*   Updated: 2024/05/01 17:46:11 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_str(t_dll **stack_a, t_dll **stack_b, char *str)
{
	if (!ft_strncmp("sa\n", str, 3))
		return (checker_swap(stack_a, stack_b, MOVE_A), 1);
	else if (!ft_strncmp("ra\n", str, 3))
		return (checker_rotate(stack_a, stack_b, MOVE_A), 1);
	else if (!ft_strncmp("rra\n", str, 4))
		return (checker_r_rotate(stack_a, stack_b, MOVE_A), 1);
	else if (!ft_strncmp("pa\n", str, 3))
		return (checker_pa(stack_a, stack_b), 1);
	else if (!ft_strncmp("sb\n", str, 3))
		return (checker_swap(stack_a, stack_b, MOVE_B), 1);
	else if (!ft_strncmp("rb\n", str, 3))
		return (checker_rotate(stack_a, stack_b, MOVE_B), 1);
	else if (!ft_strncmp("rrb\n", str, 4))
		return (checker_r_rotate(stack_a, stack_b, MOVE_B), 1);
	else if (!ft_strncmp("pb\n", str, 3))
		return (checker_pb(stack_b, stack_a), 1);
	else if (!ft_strncmp("ss\n", str, 3))
		return (checker_swap(stack_a, stack_b, MOVE_BOTH), 1);
	else if (!ft_strncmp("rr\n", str, 3))
		return (checker_rotate(stack_a, stack_b, MOVE_BOTH), 1);
	else if (!ft_strncmp("rrr\n", str, 4))
		return (checker_r_rotate(stack_a, stack_b, MOVE_BOTH), 1);
	else
		return (0);
}

static void	read_move(t_dll **stack_a, t_dll **stack_b)
{
	char	*str;

	str = gnl(0);
	while (str && ft_strncmp("\n", str, 3))
	{
		if (!check_str(stack_a, stack_b, str))
			{
				free(str);
				dll_clear(stack_a);
				write(1, "Error\n", 6);
				exit(EXIT_SUCCESS);
			}
		free(str);
		str = gnl(0);
	}
	if (str)
		free(str);
}

int	main(int ac, char **av)
{
	int		i;
	t_dll	*stack_a;
	t_dll	*stack_b;

	i = 0;
	stack_a = checker_parse_input(ac, av);
	if (!stack_a)
		return (0);
	stack_b = NULL;
	read_move(&stack_a, &stack_b);
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (stack_a)
		dll_clear(&stack_a);
	if (stack_b)
		dll_clear(&stack_b);
	return (0);
}
