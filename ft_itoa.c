/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:16:31 by joaocard          #+#    #+#             */
/*   Updated: 2023/04/18 12:26:36 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t	len;
	int		i;

	i = n;
	len = 0;
	if (i < 0)
	{
		len++;
	}
	while (i)
	{
		len++;
		i /= 10;
	}
	return (len - 1);
}

char	*ft_itoa(int n)
{
	long	nlong;
	char	*istr;
	int		len;

	len = get_len(n) + 1;
	istr = (char *)malloc(sizeof(char) * len + 1);
	if (!istr)
		return (NULL);
	nlong = n;
	if (nlong == 0)
		*(istr + 0) = '0';
	if (nlong < 0)
	{
		*(istr + 0) = '-';
		nlong *= -1;
	}
	*(istr + len) = '\0';
	len -= 1;
	while (nlong)
	{
		istr[len] = (nlong % 10) + '0';
		len--;
		nlong /= 10;
	}
	return (istr);
}

/*int main()
{
	int n = 123;
	printf("%s\n", ft_itoa(n));
	return 0;
}*/