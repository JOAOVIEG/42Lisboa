/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilis1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:57:11 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/11 16:05:59 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/libft.h"

void	free_stack(t_list **stack)
{
	t_list	*temp;
	
	temp = *stack;
	if (!(*stack))
		return ;
	while (temp)
	{
		temp = (*stack)->next;
		(*stack)->content = 0;
		free(temp);
	}
	*stack = temp; 
}
