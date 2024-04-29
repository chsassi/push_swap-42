#include "push_swap.h"

void	checker_swap_op(t_dll **stack_a)
{
	t_dll	*head;
	int		tmp_value;

	head = *stack_a;
	tmp_value = head->value;
	head->value = head->next->value;
	head->next->value = tmp_value;
}

void	checker_swap(t_dll **stack_a, t_dll **stack_b, int flag)
{
	if (flag == MOVE_A)
		checker_swap_op(stack_a);
	else if (flag == MOVE_B)
		checker_swap_op(stack_b);
	else if (flag == MOVE_BOTH)
	{
		checker_swap_op(stack_a);
		checker_swap_op(stack_b);
	}
}