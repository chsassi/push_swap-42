/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:16:28 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/19 20:41:08 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_dll	*stack_a;
	int		len;

	stack_a = (t_dll *){0};
	len = 0;
	stack_a = init_stack(ac, av);
	len = dll_size(stack_a);
	if (len <= 5)
		minisort(stack_a);
	else
		print_stack(stack_a);
	//free(stack_a);
	return (0);
}

/* int main()
{
	t_dll *head;
	t_dll *n1;
	t_dll *n2;
	t_dll *n3;
	t_dll *n4;
	t_dll *n5;

	head = NULL;

	n1 = dll_new(10);
	n1->index = 0;
	dll_add_back(&head, n1);
	n2 = dll_new(2);
	n2->index = 1;
	dll_add_back(&head, n2);
	n3 = dll_new(5);
	n3->index = 2;
	dll_add_back(&head, n3);
	n4 = dll_new(-1);
	n4->index = 3;
	dll_add_back(&head, n4);
	n5 = dll_new(8);
	n5->index = 4;
	dll_add_back(&head, n5);
	//head = solve_5(head);
	int i = 0;
	while (i < 5)
	{
		printf("%i\n",find_min_value(head));
		i++;
	}
	return (0); 
} */
