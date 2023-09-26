/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_utilis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:33:59 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/26 16:48:03 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/push_swap.h"

int	find_min(t_list **stack_a)
{
	int		min_a;
	t_list	*current;

	min_a = (*stack_a)->content;
	current = (*stack_a)->next;
	while (current)
	{
		if (current->content < min_a)
			min_a = current->content;
		current = current->next;
	}
	return (min_a);
}

int	find_max(t_list **stack_b)
{
	int		max_b;
	t_list	*current;

	max_b = (*stack_b)->content;
	current = (*stack_b)->next;
	while (current)
	{
		if (current->content > max_b)
			max_b = current->content;
		current = current->next;
	}
	return (max_b);
}

void	sort_and_push2b_big(t_list **stack_a, t_list **stack_b)
{
	int	pos_min_a_first;
	int	pos_min_a_second;

	while (ft_lstsize(*stack_a) >= 3)
	{
		pos_min_a_first = find_min_a(stack_a);
		pos_min_a_second = find_min_second(*stack_a);
		*stack_a = get_minimal_sort(stack_a, stack_b, \
				pos_min_a_first, pos_min_a_second);
	}
}

void	sort_and_push2b_small(t_list **stack_a, t_list **stack_b)
{
	while ((ft_lstsize(*stack_a) < 3) \
		&& (ft_lstsize(*stack_a) != 1) && (*stack_a))
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
		{
			pb(stack_a, stack_b);
		}
		else if ((*stack_a)->content < (*stack_a)->next->content)
		{
			sa(stack_a);
			pb(stack_a, stack_b);
		}
	}
}
