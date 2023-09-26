/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:46:36 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/26 16:48:50 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/push_swap.h"

void	sort(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	if (ft_lstsize(*stack_a) == 2)
		sort2(stack_a);
	else if (ft_lstsize(*stack_a) <= 3)
		sort3(stack_a);
	else if (ft_lstsize(*stack_a) <= 5)
		sort5(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) > 5)
		insertion_sort(stack_a, stack_b);
}

int	is_sorted(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}
