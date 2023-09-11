/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:27:27 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/11 15:43:13 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/libft.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*to_a;
	
	if (!(stack_b))
		ft_lstnew((*stack_a)->content);
	*stack_a = *stack_b;
	to_a = *stack_a;
	*stack_b  = (*stack_b)->next;
	(*stack_a)->next = to_a;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*to_b;
	
	if (!(stack_a))
		return ;
	*stack_b = *stack_a;
	to_b = *stack_b;
	*stack_a  = (*stack_a)->next;
	(*stack_b)->next = to_b;
	write(1, "pb\n", 3);
}

/*void	rrr(t_list *stack_a, t_list *stack_b)
{

}*/