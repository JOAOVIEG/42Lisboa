/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:11:53 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/08 20:37:34 by joaocard         ###   ########.fr       */
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

#endif