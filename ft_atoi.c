/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:37:36 by joaocard          #+#    #+#             */
/*   Updated: 2023/04/21 13:07:00 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdlib.h>

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	integer;

	sign = 1;
	integer = 0;
	while (*(char *)nptr == 32 || (*(char *)nptr >= 9 && *(char *)nptr <= 13))
		nptr++;
	if (*(char *)nptr == '-' || *(char *)nptr == '+')
	{
		if (*(char *)nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*(char *)nptr)
	{
		if (ft_isdigit(*(char *)nptr))
			integer = (integer * 10) + *(char *)nptr - '0';
		else
			return (sign * integer);
		nptr++;
	}
	return (sign * integer);
}

/*int main()
{
	char *str = "-123414567";
	printf("ft_atoi: %d\n", ft_atoi(str));
	printf("atoi: %d\n", atoi(str));
}*/