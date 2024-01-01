/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:06:34 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/28 10:43:14 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_memcmp(const void *sn1, const void *sn2, size_t nb)
{
	size_t	i;

	i = 0;
	while (i < nb)
	{
		if (*(unsigned char *)(sn1 + i) != *(unsigned char *)(sn2 + i))
			return (*(unsigned char *)(sn1 + i) - *(unsigned char *)(sn2 + i));
		i++;
	}
	return (0);
}

/*int main()
{
    char *str1 = "Joao Aiegas";
    char *str2 = "Joao Begas";
   printf("%d\n", ft_memcmp(str1, str2, sizeof (char) * 11));
   printf("%d\n", memcmp(str1, str2, sizeof (char) * 11));
}*/