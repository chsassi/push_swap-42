#include "libft.h"

t_dll	*dll_iterate(t_dll *lst)
{
	t_dll	*new;

	if (!lst)
		return (NULL);
	new = lst;
	while (new->next != NULL)
		new = new->next;
	return (new);
}