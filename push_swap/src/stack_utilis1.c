/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilis1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:57:11 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/12 11:21:36 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/libft.h"

void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a, to_zero);
	ft_lstclear(stack_b, to_zero);
}

int	to_zero(int *zero)
{
	return (*ft_memset(zero, 0, 4));
}
