/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:45:10 by chsassi           #+#    #+#             */
/*   Updated: 2024/05/01 17:45:11 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	checker_pa(t_dll **stack_a, t_dll **stack_b);
void	checker_pb(t_dll **stack_b, t_dll **stack_a);
void	checker_rotate_op(t_dll **stack);
void	checker_rotate(t_dll **stack_a, t_dll **stack_b, int flag);
void	checker_r_rotate_op(t_dll **stack);
void	checker_r_rotate(t_dll **stack_a, t_dll **stack_b, int flag);
void	checker_swap_op(t_dll **stack_a);
void	checker_swap(t_dll **stack_a, t_dll **stack_b, int flag);

t_dll	*checker_get_list_head(char **mtx);
t_dll	*checker_parse_input_string(int ac, char *av);
t_dll	*checker_parse_input_args(int ac, char **av);
t_dll	*checker_parse_input(int ac, char **av);

#endif
