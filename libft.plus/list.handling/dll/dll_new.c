#include "libft.h"

t_dll	*dll_new(int value)
{
	t_dll	*new;

	new = ft_calloc(1, sizeof(t_dll));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
