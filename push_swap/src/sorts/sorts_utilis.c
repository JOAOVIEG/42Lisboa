/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_utilis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:46:29 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/14 15:40:40 by joaocard         ###   ########.fr       */
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
	int	max_pos;
	int	min_pos;

	max_pos = find_max_a(stack_a);
	min_pos = find_min_a(stack_a);
	if (ft_lstsize(*stack_a) == 4)
	{
		case_size4(max_pos, stack_a, stack_b);
		sort3(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	if (ft_lstsize(*stack_a) > 4)
	{
		case_size4(max_pos, stack_a, stack_b);
		case_size5(min_pos, stack_a, stack_b);
		sort3(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		pa(stack_a, stack_b);
	}
}

/*void	my_insertation_sort(t_list **stack_a, t_list **stack_b)
{

}*/