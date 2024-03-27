
#include "libft.h"

void	dll_clear(t_dll **lst)
{
	t_dll	*ptr;

	while (*lst)
	{
		ptr = (*lst)->next;
		free(*lst);
		*lst = ptr;
	}
	*lst = NULL;
}