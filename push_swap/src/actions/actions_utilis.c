/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utilis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 09:04:52 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/10 11:17:52 by joaocard         ###   ########.fr       */
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
	t_list	*current_top;
	t_list	*tail;

	if (!(*stack)->next || !(*stack))
		return ;
	current_top = *stack;
	*stack = (*stack)->next;
	tail = ft_lstlast(*stack);
	tail->next = current_top;
	current_top->next = NULL;
}
