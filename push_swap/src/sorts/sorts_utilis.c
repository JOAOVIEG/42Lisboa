/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_utilis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:46:29 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/15 20:12:14 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/push_swap.h"

void	sort2(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

void	sort3(t_list **stack_a)
{
	if (case1(stack_a))
		sa(stack_a);
	if (case2(stack_a))
	{
		sa(stack_a);
		rra(stack_a);
	}
	if (case3(stack_a))
	{
		ra(stack_a);
	}
	if (case4(stack_a))
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (case5(stack_a))
	{
		rra(stack_a);
	}
}

void	sort5(t_list **stack_a, t_list **stack_b)
{
	int	min_pos;

	min_pos = find_min_a(stack_a);
	if (ft_lstsize(*stack_a) == 4)
	{
		case_size4(min_pos, stack_a, stack_b);
		sort3(stack_a);
		pa(stack_a, stack_b);
	}
	else
	{
		case_size5(min_pos, stack_a, stack_b);
		min_pos = find_min_a(stack_a);
		case_size4(min_pos, stack_a, stack_b);
		sort3(stack_a);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

/*void	my_insertation_sort(t_list **stack_a, t_list **stack_b)
{

}*/