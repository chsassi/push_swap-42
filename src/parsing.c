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

t_dll	*get_dll(char **mtx, t_dll *ptr)
{
	t_dll	*lst;
	int		i;
	int		nbr;

	i = 0;
	while(mtx && mtx[i])
	{
		nbr = ft_atoi(mtx[i]);
		lst = dll_new(nbr);
		if (!lst)
			return (dll_clear(&ptr), NULL);
		dll_add_back(&ptr, lst);
		i++;
	}
	return (lst);
}
char	**check_mtx(char *str)
{
	char	**mtx;
	int 	i;
	int		j;

	i = 0;
	mtx = ft_split(str, ' ');
	while (mtx && mtx[i])
	{
		j = 0;
		while (mtx[i][j])
		{
			if (mtx[i][j] == '-' || mtx[i][j] == '+')
			{
				if (!(mtx[i][j + 1] >= '0' && mtx[i][j + 1] <= '9'))
					return (free_mtx(mtx), NULL);
			}
			else if (!(mtx[i][j] >= '0' && mtx[i][j] <= '9'))
				return (free_mtx(mtx), NULL);
			j++;
		}
		i++;
	}
	return (mtx);
}

int	parse_args(int ac, char **av)
{
	char	**mtx;
	t_dll	*ptr;

	ptr = NULL;
	if (ac == 1 || !av[1])
		return (0);
	if (ac == 2)
	{
		mtx = check_mtx(av[1]);
		if (!mtx)
			ft_printf("Error");
		ptr = get_dll(mtx, ptr);
	}
	else if (ac > 2)
	{
		// piu argomenti
	}
	return (0);
}

