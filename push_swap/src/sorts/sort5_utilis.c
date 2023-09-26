/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5_utilis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:47:49 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/26 16:49:58 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/push_swap.h"

int	find_min_a(t_list **stack_a)
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
	return (elem_pos(stack_a, min_a));
}

int	elem_pos(t_list **stack_a, int extreme)
{
	t_list	*current;
	int		elem_pos;

	elem_pos = 1;
	current = (*stack_a);
	while (current->content != extreme)
	{
		elem_pos++;
		current = current->next;
	}
	return (elem_pos);
}

void	case_size4(int elem_pos, t_list **stack_a, t_list **stack_b)
{
	if (elem_pos <= 3)
	{
		while (elem_pos-- != 1)
		{
			ra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	case_size5(int elem_pos, t_list **stack_a, t_list **stack_b)
{
	if (elem_pos <= 3)
	{
		while (elem_pos-- != 1)
		{
			ra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	else
	{
		while (elem_pos++ != 6)
			rra(stack_a);
		pb(stack_a, stack_b);
	}
}
