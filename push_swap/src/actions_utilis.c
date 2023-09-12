/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utilis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 09:04:52 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/12 13:51:16 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/libft.h"

void	swap(t_list **stack)
{
	t_list	*first;

	first = *stack;
	*stack = (*stack)->next;
	if (!(*stack)->next)
		return ;
	ft_lstadd_front(&(*stack)->next, first);
}

void	rotate(t_list **stack)
{
	t_list	*top_top;
	t_list	*tail;

	if (!(*stack)->next || !(*stack))
		return ;
	top_top = *stack;
	*stack = (*stack)->next;
	tail = ft_lstlast(*stack);
	tail->next = top_top;
	top_top->next = NULL;
}

void	push(t_list **from_stack, t_list **to_stack)
{
	t_list *new_top;
	
	new_top = (*from_stack)->next;
	ft_lstadd_front(to_stack, *from_stack);
	(*from_stack) = new_top;
}

void	rev_rotate(t_list **stack)
{
	t_list	*top = *stack;
    t_list *tail = NULL;
    if (!(*stack) || !((*stack)->next))
		return ;
	while (top->next)
	{
		tail = top;
		top = top->next;
	}
    tail->next = NULL;
    top->next = *stack;
    *stack = top;
}