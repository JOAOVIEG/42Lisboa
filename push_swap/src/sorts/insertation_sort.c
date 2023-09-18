/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertation_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:16:28 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/18 18:27:55 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/push_swap.h"

void insertion_sort(t_list **stack_a, t_list **stack_b)
{
    int size;
    int pos_min_a_first;
    int pos_min_a_second;
    int middle;
    
    while (ft_lstsize(*stack_a) > 5)
    {
        size = ft_lstsize(*stack_a);
        middle = get_middle(size);
        pos_min_a_first = find_min_a(stack_a);
        pos_min_a_second = find_min_second(*stack_a);
        *stack_a = get_minimal_sort(stack_a, stack_b, pos_min_a_first, pos_min_a_second, middle);
    }
	if (ft_lstsize(*stack_a) == 5)
	{
		sort5(stack_a, stack_b);
		while (*stack_b)
		{
			pa(stack_a, stack_b);
		}
	}
}

int	find_min_second(t_list *stack_a)
{
	int	min;
	int min2;
	t_list	*current;

	min = find_min(&stack_a);
	min2 = stack_a->content;
	current = stack_a->next;
	while (current)
	{
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

t_list	*get_minimal_sort(t_list **stack_a, t_list **stack_b, int pos_min_a_first, int pos_min_a_second, int middle)
{
	if (pos_min_a_first <= middle && pos_min_a_second <= middle)
	{
		while (pos_min_a_first-- != 1)
			ra(stack_a);
		pb(stack_a, stack_b);
		while (pos_min_a_second-- != 1)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (pos_min_a_first > middle && pos_min_a_second > middle)
	{
		while (pos_min_a_first-- != 1)
			rra(stack_a);
		pb(stack_a, stack_b);
		while (pos_min_a_second-- != 1)
			rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (pos_min_a_first <= middle && pos_min_a_second > middle)
	{
		while (pos_min_a_first-- != 1)
			ra(stack_a);
		pb(stack_a, stack_b);
		while (pos_min_a_second-- != 1)
			rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (pos_min_a_first > middle && pos_min_a_second <= middle)
	{
		while (pos_min_a_first-- != 1)
			rra(stack_a);
		pb(stack_a, stack_b);
		while (pos_min_a_second-- != 1)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	return (*stack_a);
}

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
