#include "push_swap.h"

static void	check_str(t_dll **stack_a, t_dll **stack_b, char *str)
{
	if (!ft_strncmp("sa\n", str, 3))
		swap(stack_a, stack_b, MOVE_A);
	if (!ft_strncmp("ra\n", str, 3))
		rotate(stack_a, stack_b, MOVE_A);
	if (!ft_strncmp("rra\n", str, 4))
		r_rotate(stack_a, stack_b, MOVE_A);
	if (!ft_strncmp("pa\n", str, 3))
		pa(stack_a, stack_b);
	if (!ft_strncmp("sb\n", str, 3))
		swap(stack_a, stack_b, MOVE_B);
	if (!ft_strncmp("rb\n", str, 3))
		rotate(stack_a, stack_b, MOVE_B);
	if (!ft_strncmp("rrb\n", str, 4))
		r_rotate(stack_a, stack_b, MOVE_B);
	if (!ft_strncmp("pb\n", str, 3))
		pb(stack_a, stack_b);
	if (!ft_strncmp("ss\n", str, 3))
		swap(stack_a, stack_b, MOVE_BOTH);
	if (!ft_strncmp("rr\n", str, 3))
		rotate(stack_a, stack_b, MOVE_BOTH);
	if (!ft_strncmp("rrr\n", str, 4))
		r_rotate(stack_a, stack_b, MOVE_BOTH);
}

int main(int ac, char **av)
{
	char	*str;
	t_dll	*stack_a;
	t_dll	*stack_b;

	stack_a = parse_input(ac, av);
	stack_b = NULL;
	str = NULL;
	while (42)
	{
		str = gnl(0);
		if (is_sorted(stack_a) || str == NULL)
		{
			free(str);
			break ;
		}
		check_str(&stack_a, &stack_b, str);
		free(str);
	}
	if (is_sorted(stack_a) && !stack_b)
		ft_printf("OK");
	else
		ft_printf("KO");
	return (0);
}
