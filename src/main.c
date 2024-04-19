/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:16:28 by chsassi           #+#    #+#             */
/*   Updated: 2024/03/30 15:44:50 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_dll	*list;
	int		len;

	list = NULL;
	if (ac == 1 || !av[1] || !av[1][0])
		return (0);
	if (ac == 2)
		list = parse_input_string(ac, av);
	else if (ac > 2)
		list = parse_input_args(ac, &av[1]);
	if ((list && is_sorted(list)) || !list)
		return (0);
	len = dll_size(list);
	if (len == 3)
		solve_3(list);
	else if (len == 4)
		solve_4(list);
	else if (len == 5)
		solve_5(list);
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
		printf("%i\n", head->value);
		i++;
	} 
}
*/