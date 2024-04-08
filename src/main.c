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

	list = NULL;
	if (ac == 1 || !av[1] || !av[1][0])
		return (0);
	if (ac == 2)
		list = parse_input_string(ac, av);
	else if (ac > 2)
		list = parse_input_args(ac, &av[1]);
	if ((list && is_sorted(list)) || !list)
		return (0);
	

	return (0);
}
