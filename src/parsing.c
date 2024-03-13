/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:16:28 by chsassi           #+#    #+#             */
/*   Updated: 2024/03/13 19:16:33 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	control_alpha(char **mtx)
{
	int	i;

	i = 0;
	while (ft_isint(mtx[i]))
	{
		
	}
	return (1);
}

int	parse_args(int ac, char **av)
{
	char	**mtx;

	if (ac == 2)
	{
		mtx = ft_split(av[1], ' ');
		if (!control_alpha(mtx))
		{
			ft_printf("Error!\n");
			return (0);
		}
		else
			ft_atoi(mtx);
	}
}

