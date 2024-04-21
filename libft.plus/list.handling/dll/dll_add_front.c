/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_add_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:02:25 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/03 14:02:33 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dll_add_front(t_dll **lst, t_dll *new)
{
	if (!*lst)
	{
		new->prev = NULL;
		new->next = NULL;
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	new->next = *lst;
	(*lst)->prev = new;
	new->prev = NULL;
	*lst = new;
}
