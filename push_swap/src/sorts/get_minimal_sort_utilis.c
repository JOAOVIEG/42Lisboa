/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_minimal_sort_utilis.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:46:42 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/26 16:39:19 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/push_swap.h"

void	first_bucket(t_list **stack_a, t_list **stack_b, \
					int pos_min_a_first, int pos_min_a_second)
{
	int	middle;

	middle = get_middle(ft_lstsize(*stack_a));
	if ((pos_min_a_first <= middle && pos_min_a_second <= middle) \
							&& pos_min_a_first < pos_min_a_second)
	{
		while (pos_min_a_first-- != 1)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((pos_min_a_first <= middle && pos_min_a_second <= middle) \
							&& pos_min_a_first > pos_min_a_second)
	{
		while (pos_min_a_second-- != 1)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	second_bucket(t_list **stack_a, t_list **stack_b, \
					int pos_min_a_first, int pos_min_a_second)
{
	int	middle;

	middle = get_middle(ft_lstsize(*stack_a));
	if ((pos_min_a_first > middle && pos_min_a_second > middle) \
							&& pos_min_a_first < pos_min_a_second)
	{
		while (pos_min_a_second++ != (ft_lstsize(*stack_a) + 1))
			rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((pos_min_a_first > middle && pos_min_a_second > middle) \
							&& pos_min_a_first > pos_min_a_second)
	{
		while (pos_min_a_first++ != (ft_lstsize(*stack_a) + 1))
			rra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	both_buckets(t_list **stack_a, t_list **stack_b, \
					int pos_min_a_first, int pos_min_a_second)
{
	int	middle;

	middle = get_middle(ft_lstsize(*stack_a));
	if ((pos_min_a_first <= middle && pos_min_a_second > middle) \
			&& (middle - pos_min_a_first) <= (pos_min_a_second - middle))
	{
		while (pos_min_a_first-- != 1)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((pos_min_a_first <= middle && pos_min_a_second > middle) \
				&& (middle - pos_min_a_first) > (pos_min_a_second - middle))
	{
		while (pos_min_a_second++ != (ft_lstsize(*stack_a) + 1))
			rra(stack_a);
		pb(stack_a, stack_b);
	}
}
