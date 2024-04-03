/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:47:09 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/03 14:02:33 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
