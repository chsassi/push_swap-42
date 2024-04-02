/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:16:28 by chsassi           #+#    #+#             */
/*   Updated: 2024/03/30 15:44:50 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dll	*get_list(char **mtx)
{
	t_dll	*lst;
	int		i;
	t_dll *head = NULL;

	i = 0;
	while (mtx && mtx[i])
	{
		lst = dll_new(ft_atoi(mtx[i]));
		if (!lst)
			return (dll_clear(&head), NULL);
		lst->index = i;
		dll_add_back(&head, lst);
		i++;
	}
	return (free_mtx(mtx), head);
}

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

t_dll	*parse_input_string(int ac, char **av)
{
	char	**mtx;
	t_dll	*head;

	head = (t_dll *){0};
	(void)ac;

	mtx = ft_split(av[1], ' ');
	if (!mtx || !mtx_check(mtx))
		return (free_mtx(mtx), ft_printf("Error\n"), NULL);
	head = get_list(mtx);
	if (!head)
		return (dll_clear(&head), free_mtx(mtx), ft_printf("Error\n"), NULL);
	return (head);
}

t_dll *parse_input_args(int ac, char **av)
{
	t_dll	*head;
	char	**mtx;
	int		i;
	(void)ac;

	mtx = NULL;
	head = (t_dll *){0};
	i = 0;
	if (!mtx_check(av))
		return (ft_printf("Error\n"), NULL);
	mtx = ft_calloc(ac, sizeof(char *));
	if (!mtx)
		return (free_mtx(mtx), NULL);
	while (av[i])
	{
		mtx[i] = ft_strdup(av[i]);
		i++;
	}
	head = get_list(mtx);
	if (!head)
		return (dll_clear(&head), free_mtx(mtx), ft_printf("Error\n"), NULL);
	return (head);
}

int	is_sorted(t_dll *list)
{
	t_dll	*temp;

	temp = list;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (dll_clear(&list), 1);
}
