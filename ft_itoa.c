/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:16:31 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/02 00:31:18 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t	len;
	int		i;

	i = n;
	len = 0;
	if (i == 0)
		return (1);
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

static	char	*check_zero_add_memory(long nlong, int len)
{
	char	*istr;

	if (nlong == 0)
	{
		istr = (char *)malloc(sizeof(char) * len);
		istr[0] = 48;
		istr[len - 1] = '\0';
		return (istr);
	}
	istr = (char *)malloc(sizeof(char) * len + 1);
	return (istr);
}

char	*ft_itoa(int n)
{
	long	nlong;
	char	*str;
	int		len;

	len = get_len(n) + 1;
	nlong = n;
	str = check_zero_add_memory(nlong, len);
	if (!str)
		return (NULL);
	if (nlong < 0)
	{
		*(str + 0) = '-';
		nlong *= -1;
	}
	*(str + len) = '\0';
	len -= 1;
	while (nlong)
	{
		str[len] = (nlong % 10) + '0';
		len--;
		nlong /= 10;
	}
	return (str);
}

/*int main()
{
	int n = 123;
	printf("%s\n", ft_itoa(n));
	return 0;
}*/