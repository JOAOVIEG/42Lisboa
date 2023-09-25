/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertation_sort_utilis.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:33:59 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/25 21:07:07 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../inc/push_swap.h"

t_list	*update_stack_b(t_list *stack_b)
{
	t_list	*current;
	t_list	*next;
	t_list	*prev;

	current = stack_b;
	next = current->next;
	prev = NULL;
	while (next)
	{
		if (current->content < next->content)
		{
			if (prev)
				prev->next = next;
			else
				stack_b = next;
			current->next = next->next;
			next->next = current;
			prev = next;
			next = current->next;
		}
		else
		{
			prev = current;
			current = next;
			next = next->next;
		}
	}
	return (stack_b);
}
 