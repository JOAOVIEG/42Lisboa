/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:46:36 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/14 13:10:08 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/push_swap.h"

/***TODO***/
/*I have to check if stack is sorted in the first place as well*/

void	sort(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	if (ft_lstsize(*stack_a) == 2)
		sort2(stack_a);
	if (ft_lstsize(*stack_a) <= 3)
		sort3(stack_a);
	if (ft_lstsize(*stack_a) <= 5)
		sort5(stack_a, stack_b);
}

	/*if (ft_lstsize(*stack_a) > 5)
		my_insertation_sort(stack_a, stack_b);*/