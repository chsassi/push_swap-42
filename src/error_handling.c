#include "push_swap.h"

int	check_args(int ac, char **av)
{
	int i;
	(void)av;
	(void)i;

	if (ac < 2)
		return(0);
	return (1);
}

int	print_error(int error_nbr)
{
	if (error_nbr == -1)
		ft_printf("ERROR!\n");
	else if (error_nbr == -2)
		ft_printf("ERROR!\n");
	else if (error_nbr == -3)
		ft_printf("ERROR!\n");
	return (0);
}