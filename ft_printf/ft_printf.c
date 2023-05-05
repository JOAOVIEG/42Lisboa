/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:28:11 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/05 16:22:08 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_printf(const char *fixed_arg, ...)
{
	va_list	ptr;
	int		output;

	output = 0;
	va_start(ptr, fixed_arg);
	while (*fixed_arg)
	{
		if (*fixed_arg == '%')
			output += print_format(*(fixed_arg + 1), ptr);
		else
			output += write(1, *fixed_arg, 1);
		fixed_arg++;
	}
	va_end(ptr);
	return (output);
}

/*int	main(void)
{
	char *a = "This string is a simple example.";
	char b = "b";
    int i = 42;

    ft_printf("Printing the simple example: %s\n", a);
    
}*/