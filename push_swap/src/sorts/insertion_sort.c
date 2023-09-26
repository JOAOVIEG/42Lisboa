/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:16:28 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/26 16:45:02 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/push_swap.h"

void	insertion_sort(t_list **stack_a, t_list **stack_b)
{
	sort_and_push2b_big(stack_a, stack_b);
	sort_and_push2b_small(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (*stack_b)
	{
		sort_b_max_on_top(stack_b);
		pa(stack_a, stack_b);
	}
}

int	find_min_second(t_list *stack_a)
{
	int		min;
	int		min2;
	t_list	*current;

	min = find_min(&stack_a);
	min2 = stack_a->content;
	current = stack_a->next;
	while (current)
	{
		if (min2 == min)
			min2 = stack_a->next->content;
		if (current->content < min2 && current->content != min)
			min2 = current->content;
		current = current->next;
	}
	return (elem_pos(&stack_a, min2));
}

int	get_middle(int size)
{
	int	middle;

	if (size % 2 == 0)
		middle = (size / 2);
	else
		middle = (size / 2) + 1;
	return (middle);
}

t_list	*get_minimal_sort(t_list **stack_a, t_list **stack_b, \
				int pos_min_a_first, int pos_min_a_second)
{
	int	middle;

	first_bucket(stack_a, stack_b, pos_min_a_first, pos_min_a_second);
	second_bucket(stack_a, stack_b, pos_min_a_first, pos_min_a_second);
	both_buckets(stack_a, stack_b, pos_min_a_first, pos_min_a_second);
	middle = get_middle(ft_lstsize(*stack_a));
	if ((pos_min_a_first > middle && pos_min_a_second <= middle) \
				&& (middle - pos_min_a_second) < (pos_min_a_first - middle))
	{
		while (pos_min_a_second-- != 1)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((pos_min_a_first > middle && pos_min_a_second <= middle) \
				&& (middle - pos_min_a_second) >= (pos_min_a_first - middle))
	{
		while (pos_min_a_first++ != (ft_lstsize(*stack_a) + 1))
			rra(stack_a);
		pb(stack_a, stack_b);
	}
	return (*stack_a);
}

void	sort_b_max_on_top(t_list **stack_b)
{
	int	max;
	int	pos_max;
	int	size;

	size = ft_lstsize(*stack_b);
	max = find_max(stack_b);
	pos_max = elem_pos(stack_b, max);
	if (pos_max <= (size / 2))
	{
		while (pos_max-- != 1)
			rb(stack_b);
	}
	else
	{
		while (pos_max++ != (size + 1))
			rrb(stack_b);
	}
}
