#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef enum e_error
{
	NBR_NOT_FOUND,
	DUPLICATES,
	INT_RANGE,
}	t_error;

int	check_args(int ac, char **av);
int	parse_args(int ac, char **av);

# endif