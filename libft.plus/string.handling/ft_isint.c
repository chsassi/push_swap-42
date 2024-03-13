/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:44:41 by chsassi           #+#    #+#             */
/*   Updated: 2024/03/13 19:44:45 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(char *str)
{
	int i;

	i = -1;
	while (str && str[++i])
	{
		if (str[0] == '-' || (str[i] >= '0' && str[i] <= '9'))
			return (1);
	}
	return (0);
}
