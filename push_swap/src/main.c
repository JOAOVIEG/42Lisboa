/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:23:26 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/11 16:01:39 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*temp_a;
	t_list	*temp_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		exit(EXIT_FAILURE);
	}
	push_to_stack(argv, argc, &stack_a);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	temp_a = stack_a;
	temp_b = stack_b;
	/*while (temp != NULL)
	{
		printf("%d ", temp->content);
		temp = temp->next;
	}*/
	free_stack(&stack_a);
	free_stack(&stack_b);
	printf("\n");
}
