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

t_dll	*get_list(char **mtx, t_dll *head)
{
	t_dll	*lst;
	int		i;
	int		nbr;

	i = 0;
	while (mtx && mtx[i])
	{
		nbr = ft_atoi(mtx[i]);
		lst = dll_new(nbr);
		if (!lst)
			return (dll_clear(&head), NULL);
		dll_add_back(&head, lst);
		i++;
	}
	return (head);
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
					return (free_mtx(mtx), 0);
			}
			else if (!(mtx[i][j] >= '0' && mtx[i][j] <= '9'))
				return (free_mtx(mtx), 0);
			j++;
		}
		i++;
	}
	if (!check_duplicates(mtx))
		return (0);
	return (1);
}

int	parse_input_string(t_dll *head, int ac, char **av)
{
	char	**mtx;
	(void)ac;

	head = NULL;
	mtx = ft_split(av[1], ' ');
	if (!mtx || !mtx_check(mtx))
		return (free_mtx(mtx), ft_printf("Error\n"), 0);
	head = get_list(mtx, head);
	if (!head)
		return (dll_clear(&head), free_mtx(mtx), ft_printf("Error\n"), 0);
	return (1);
}

int	parse_input_args(t_dll *head, int ac, char **av)
{
	char	**mtx;
	int		i;
	(void)ac;

	mtx = NULL;
	head = NULL;
	i = 0;
	if (!mtx_check(av))
		return (free_mtx(mtx), ft_printf("Error\n"), 0);
	mtx = (char **)malloc(sizeof(char *) * (ac - 1));
	if (!mtx[i])
		return (free_mtx(mtx), 0);
	while (av[i])
	{
		mtx[i] = ft_strdup(av[i]);
		if (!mtx[i])
			return (free_mtx(mtx), 0);
		i++;
	}
	head = get_list(mtx, head);
	if (!head)
		return (dll_clear(&head), free_mtx(mtx), ft_printf("Error\n"), 0);
	return (1);
}

int	parse_args(int ac, char **av)
{
	t_dll	head;

	head = (t_dll){0};
	if (ac == 1 || !av[1] || !av[1][0])
		return (0);
	if (ac == 2)
		parse_input_string(&head, ac, av);
	else if (ac > 2)
		parse_input_string(&head, ac, av);
	return (1);
}
