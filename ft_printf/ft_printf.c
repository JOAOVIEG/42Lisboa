/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:28:11 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/11 16:30:25 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(const char format, va_list ptr)
{
	int	output;

	output = 0;
	if (format == 'c')
		output = printchar(va_arg(ptr, int));
	if (format == '%')
		output = printchar('%');
	if (format == 's')
		output += printstr(va_arg(ptr, char *));
	if (format == 'i' || format == 'd')
		output = print_base_nbr(va_arg(ptr, int), 10, DECIMAL);
	if (format == 'u')
		output = print_base_u_nbr(va_arg(ptr, unsigned int), 10, DECIMAL);
	if (format == 'x')
		output = print_base_u_nbr(va_arg(ptr, unsigned int), \
													16, LOWER_HEXADECIMAL);
	if (format == 'X')
		output = print_base_u_nbr(va_arg(ptr, unsigned int), \
													16, UPPER_HEXADECIMAL);
	if (format == 'p')
		output = printptr(va_arg(ptr, unsigned long int), LOWER_HEXADECIMAL);
	return (output);
}

int	ft_printf(const char *fixed_arg, ...)
{
	va_list	ptr;
	int		output;
	int		i;

	output = 0;
	i = 0;
	va_start(ptr, fixed_arg);
	while (*(fixed_arg + i))
	{
		if (*(fixed_arg + i) == '%')
		{
			output += print_format(*(fixed_arg + i + 1), ptr);
			i++;
		}
		else
			output += write(1, &*(fixed_arg + i), 1);
		i++;
	}
	va_end(ptr);
	return (output);
}

/*int	main(void)
{
	int i = INT_MIN;
    ft_printf("Printing the simple example: %d\n", i);
    printf("Printing the simple example: %d", i);
}*/