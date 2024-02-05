#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_stack
{
	int		value;
	int		index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;


int	check_args(int ac, char **av);

# endif