#include "push_swap.h"

static void	check_str(t_dll **stack_a, t_dll **stack_b, char *str)
{
	if (!ft_strncmp("sa\n", str, 3))
		checker_swap(stack_a, stack_b, MOVE_A);
	else if (!ft_strncmp("ra\n", str, 3))
		checker_rotate(stack_a, stack_b, MOVE_A);
	else if (!ft_strncmp("rra\n", str, 4))
		checker_r_rotate(stack_a, stack_b, MOVE_A);
	else if (!ft_strncmp("pa\n", str, 3))
		checker_pa(stack_a, stack_b);
	else if (!ft_strncmp("sb\n", str, 3))
		checker_swap(stack_a, stack_b, MOVE_B);
	else if (!ft_strncmp("rb\n", str, 3))
		checker_rotate(stack_a, stack_b, MOVE_B);
	else if (!ft_strncmp("rrb\n", str, 4))
		checker_r_rotate(stack_a, stack_b, MOVE_B);
	else if (!ft_strncmp("pb\n", str, 3))
		checker_pb(stack_b, stack_a);
	else if (!ft_strncmp("ss\n", str, 3))
		checker_swap(stack_a, stack_b, MOVE_BOTH);
	else if (!ft_strncmp("rr\n", str, 3))
		checker_rotate(stack_a, stack_b, MOVE_BOTH);
	else if (!ft_strncmp("rrr\n", str, 4))
		checker_r_rotate(stack_a, stack_b, MOVE_BOTH);
	else
		return ;
}

int main(int ac, char **av)
{
	char	*str;
	t_dll	*stack_a;
	t_dll	*stack_b;

	stack_a = checker_parse_input(ac, av);
	if (!stack_a)
		return (0);
	stack_b = NULL;
	str = gnl(0);
	while (str && ft_strncmp("\n", str, 3))
	{
		check_str(&stack_a, &stack_b, str);
		free(str);
		str = gnl(0);
	}
	if (str)
		free(str);
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	dll_clear(&stack_a);
	if (stack_b)
		dll_clear(&stack_b);
	return (0);
}
