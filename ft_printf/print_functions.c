/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:14:16 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/11 16:34:25 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(char c)
{
	return (write(1, &c, 1));
}

int	printstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (*(s + i))
		i++;
	return (write(1, s, i));
}

int	print_base_nbr(long long int n, long long int base, char *format)
{
	int		output;

	output = 0;
	if (n < 0)
	{
		output = printchar('-');
		n *= -1;
	}
	return (print_base_u_nbr(n, base, format));
}

int	print_base_u_nbr(unsigned long long int n, unsigned long long int base, \
															char *format)
{
	int		output;

	output = 0;
	if (n >= base)
	{
		output += print_base_nbr(n / base, base, format);
		output += print_base_nbr(n % base, base, format);
	}
	else
		output += printchar(format[n]);
	return (output);
}

int	printptr(uintptr_t ptr, char *format)
{
	if (!ptr)
		return (printstr("nill"));
	return (printstr("0x") + print_base_u_nbr(ptr, 16, format));
}
