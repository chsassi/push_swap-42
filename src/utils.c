/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:48:01 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/09 15:48:04 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(char **mtx)
{
	int	i;
	int	j;

	i = 0;
	while (mtx && mtx[i])
	{
		j = i + 1;
		while (mtx[j])
		{
			if (!ft_strncmp(mtx[i], mtx[j], 12))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	find_min(t_dll *pStack)
{
	t_dll	*tmp;
	t_dll	*tmp2;
	int		i;

	tmp = pStack;
	tmp2 = pStack->next;
	while (tmp2)
	{
		if (tmp->value > tmp2->value)
		{
			i = tmp2->index;
			tmp = tmp2;
		}
		tmp2 = tmp2->next;
	}
	return (i);
}

int	is_sorted(t_dll *pStack)
{
	t_dll	*tmp;

	tmp = pStack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (dll_clear(&pStack), 1);
}

int	mtx_check(char **mtx)
{
	int	i;
	int	j;

	i = 0;
	while (mtx && mtx[i])
	{
		j = 0;
		while (mtx[i][j])
		{
			if (mtx[i][j] == '-' || mtx[i][j] == '+')
			{
				if (!(mtx[i][j + 1] >= '0' && mtx[i][j + 1] <= '9'))
					return (0);
			}
			else if (!(mtx[i][j] >= '0' && mtx[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	if (!check_duplicates(mtx))
		return (0);
	return (1);
}
