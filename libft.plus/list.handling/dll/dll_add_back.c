#include "libft.h"

void	dll_add_back(t_dll **lst, t_dll *new)
{
	t_dll	*last;

	last = dll_last(*lst);
	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		new->prev = *lst;
		return ;
	}
	last->next = new;
	new->prev = *lst;

}
