/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_utilis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:18:12 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:34 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/push_swap.h"

int	case1(t_list **stack_a)
{
	if ((*stack_a)->content < (ft_lstlast(*stack_a))->content && \
		((*stack_a)->next->content < (*stack_a)->content))
		return (1);
	return (0);
}

int	case2(t_list **stack_a)
{
	if ((*stack_a)->next->content < (*stack_a)->content && \
		((ft_lstlast(*stack_a))->content < (*stack_a)->next->content))
		return (1);
	return (0);
}

int	case3(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content && \
		((ft_lstlast(*stack_a))->content < (*stack_a)->content))
		return (1);
	return (0);
}

int	case4(t_list **stack_a)
{
	if ((ft_lstlast(*stack_a))->content < (*stack_a)->next->content && \
		((*stack_a)->content < (ft_lstlast(*stack_a))->content))
		return (1);
	return (0);
}

int	case5(t_list **stack_a)
{
	if ((ft_lstlast(*stack_a))->content < (*stack_a)->next->content && \
		((*stack_a)->content < (*stack_a)->next->content))
		return (1);
	return (0);
}
