/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:11:53 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/15 11:04:58 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX 2147483647
# define MIN -2147483648

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

void	push_to_stack(char **argv, int argc, t_list **stack);
int		negative_digit(char *argv);
int		args_checks(char *args, t_list *stack, int value);
int		is_unique(t_list *stack, int value);
void	first_push(t_list **stack, int value);
void	free_stacks(t_list **stack_a, t_list **stack_b);
int		to_zero(int *zero);
void	sa(t_list **stack);
void	swap(t_list **stack);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	rev_rotate(t_list **from_stack);
void	push(t_list **from_stack, t_list **to_stack);
void	ra(t_list **stack_a);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	sort(t_list **stack_a, t_list **stack_b);
void	sort2(t_list **stack_a);
void	sort3(t_list **stack_a);
void	sort5(t_list **stack_a, t_list **stack_b);
int		case1(t_list **stack_a);
int		case2(t_list **stack_a);
int		case3(t_list **stack_a);
int		case4(t_list **stack_a);
int		case5(t_list **stack_a);
int     elem_pos(t_list **stack_a, int extreme);
void	case_size4(int elem_pos, t_list **stack_a, t_list **stack_b);
void	case_size5(int elem_pos, t_list **stack_a, t_list **stack_b);
int     find_min_a(t_list **stack_a);

#endif