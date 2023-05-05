/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:14:16 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/05 18:37:53 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	printchar(char c)
{
	write(1, &c, 1);
}

int	printstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (*(s + i))
		i++;
	return (write(1, s, i));
}

int	printnbr(int n)
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

int	print_format(const char format, va_list ptr)
{
	int	output;

	output = 0;
	if (format == 'c')
		output = printchar(va_arg(ptr, int));
	if (format == 's')
		output = printstr(va_arg(ptr, char *));
	if (format == 'i' || format == 'd')
		output = printnbr(va_arg(ptr, int));
	if (format == 'u')
		output = printnbr(va_arg(ptr, unsigned int));
	return (output);
}