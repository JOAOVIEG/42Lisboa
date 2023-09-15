/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:23:26 by joaocard          #+#    #+#             */
/*   Updated: 2023/09/15 19:48:48 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*to_print;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		exit(EXIT_FAILURE);
	}
	push_to_stack(argv, argc, &stack_a);
	sort(&stack_a, &stack_b);
	write(1, "\n", 1);
	to_print = stack_a;
	while (to_print)
	{
		ft_putnbr_fd(to_print->content, 1);
		write(1, " ", 1);
		to_print = to_print->next;
	}
	write(1, "\n", 1);
	free_stacks(&stack_a, &stack_b);
}
