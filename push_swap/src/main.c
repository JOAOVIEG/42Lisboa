/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:23:26 by joaocard          #+#    #+#             */
/*   Updated: 2023/10/02 12:48:49 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		exit(EXIT_FAILURE);
	}
	push_to_stack(argv, argc, &stack_a);
	if (is_sorted(&stack_a))
	{
		free_stacks(&stack_a, &stack_b);
		exit(EXIT_SUCCESS);
	}
	index_stack(&stack_a);
	sort(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
}
