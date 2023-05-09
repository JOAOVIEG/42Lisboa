/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:14:16 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/09 15:04:24 by joaocard         ###   ########.fr       */
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

int	printnbr(long n)
{
	if (n == -2147483648)
	{
		printchar('-');
		printchar('2');
		printnbr(147483648);
	}
	else if (n < 0)
	{
		printchar('-');
		printchar(-n);
	}
	else if (n >= 10)
	{
		printnbr(n / 10);
		printnbr(n % 10);
	}
	else if (n >= 0 && n <= 9)
		printchar(n + '0');
	return (0);
}

int	printhexa(int decimal, char *hexadecimal)
{
	int	output;
	int	remainder;

	output = 0;
	remainder = decimal % 16;
	if (decimal / 16 >= 16)
	{
		output += printchar(hexadecimal[remainder]);
		printhexa(decimal / 16, hexadecimal);
	}
	output += printchar(hexadecimal[remainder]);
	return (output);
}

int	printptr(uintptr_t ptr, char *hexadecimal)
{
	if (!ptr)
		return (printstr("nill"));
	return (printstr("0x") + printhexa(ptr, hexadecimal));
}
