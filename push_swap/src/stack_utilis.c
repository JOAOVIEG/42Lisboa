/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:39:58 by joaocard          #+#    #+#             */
/*   Updated: 2023/10/09 16:19:36 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/libft.h"

void	push_to_stack(char **argv, int argc, t_list **stack)
{
	int			i;
	long int	value;

	i = 1;
	while (i <= argc - 1)
	{
		value = ft_atoi(argv[i]);
		if (args_checks(argv[i], *stack, value) == 1)
		{
			first_push(stack, value);
		}
		else
		{
			write(2, "ERROR\n", 6);
			free_stacks(stack, NULL);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	args_checks(char *args, t_list *stack, long int value)
{
	if ((is_number(args)) && \
		((is_unique(stack, value) && (value >= INT_MIN \
		&& value <= INT_MAX))))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	is_number(char *argv)
{
	if (*argv == '-')
		argv++;
	if (!*argv)
		return (0);
	while (*argv)
	{
		if (!ft_isdigit(*argv))
			return (0);
		argv++;
	}
	return (1);
}

int	is_unique(t_list *stack, long int value)
{
	t_list	*tail;

	tail = stack;
	while (tail != NULL)
	{
		if (tail->content == value)
			return (0);
		tail = tail->next;
	}
	return (1);
}

void	first_push(t_list **stack, long int value)
{
	t_list	*new_element;
	t_list	*tail;

	new_element = ft_lstnew(value);
	if (!*stack)
	{
		*stack = new_element;
	}
	else
	{
		tail = ft_lstlast(*stack);
		tail->next = new_element;
	}
}
