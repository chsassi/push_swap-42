#include "push_swap.h"

t_dll	*checker_get_list_head(char **mtx)
{
	t_dll	*list;
	t_dll	*head;
	int		i;

	head = NULL;
	i = 0;
	while (mtx && mtx[i])
	{
		list = dll_new(ft_atoi(mtx[i]));
		if (!list)
			return (dll_clear(&head), NULL);
		list->index = i;
		dll_add_back(&head, list);
		i++;
	}
	return (free_mtx(mtx), head);
}

t_dll	*checker_parse_input_string(int ac, char *av)
{
	t_dll	*head;
	char	**mtx;

	(void)ac;
	head = (t_dll *){0};
	mtx = ft_split(av, ' ');
	if (!mtx || !mtx_check(mtx))
		return (free_mtx(mtx), ft_printf("Error\n"), NULL);
	head = get_list_head(mtx);
	if (!head)
		return (free_mtx(mtx), dll_clear(&head), ft_printf("Error\n"), NULL);
	return (head);
}

t_dll	*checker_parse_input_args(int ac, char **av)
{
	t_dll	*head;
	char	**mtx;
	int		i;

	(void)ac;
	head = (t_dll *){0};
	mtx = NULL;
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
	head = get_list_head(mtx);
	if (!head)
		return (dll_clear(&head), free_mtx(mtx), ft_printf("Error\n"), NULL);
	return (head);
}

t_dll	*checker_parse_input(int ac, char **av)
{
	t_dll	*stack_a;

	stack_a = NULL;
	if (ac == 1 || !av[1] || !av[1][0])
		return (0);
	if (ac == 2)
		stack_a = checker_parse_input_string(ac, av[1]);
	else if (ac > 2)
		stack_a = checker_parse_input_args(ac, &av[1]);
	if (!stack_a)
		return (0);
	return (stack_a);
}
