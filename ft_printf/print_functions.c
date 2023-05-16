/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:14:16 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/16 19:57:54 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	printchar(char c)
{
	return (write(1, &c, 1));
}

size_t	printstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (*(s + i))
		i++;
	return (write(1, s, i));
}

size_t	print_base_nbr(long int n, char *format)
{
	size_t	output;

	output = 0;
	if (n < 0)
	{
		output = printchar('-');
		n *= -1;
	}
	output += print_base_u_nbr(n, format);
	return (output);
}

size_t	print_base_u_nbr(unsigned long int n, char *format)
{
	size_t	output;
	size_t	format_base;

	output = 0;
	format_base = 0;
	while (format[format_base])
		format_base++;
	if (n >= format_base)
	{
		output += print_base_nbr(n / format_base, format);
		output += print_base_nbr(n % format_base, format);
	}
	else
		output += printchar(format[n]);
	return (output);
}

size_t	printptr(unsigned long ptr, char *format)
{
	if (!ptr)
		return (printstr("(nil)"));
	return (printstr("0x") + print_base_u_nbr(ptr, format));
}
