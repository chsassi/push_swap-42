/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:50:39 by chsassi           #+#    #+#             */
/*   Updated: 2024/03/30 15:50:41 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_dll	*get_list(char **mtx);
t_dll	*parse_input_string(int ac, char **av);
t_dll	*parse_input_args(int ac, char **av);
int		check_duplicates(char **mtx);
int		is_sorted(t_dll *list);
int		mtx_check(char **mtx);

# endif
