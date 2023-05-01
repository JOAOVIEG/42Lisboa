/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:46:50 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/02 00:32:01 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = ft_strlen((char *)little);
	if (*little == 0)
		return ((char *) big);
	if (len == 0)
		return (0);
	while (*(char *)big && (int)(len - i) != -1)
	{
		if (ft_strncmp((char *)big, (char *)little, i) == 0)
			return ((char *)big);
		len--;
		big++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	*big = "Hello World. How are you";
	char	*little = "World";

	printf("%s\n", ft_strnstr(big, little, sizeof(char) * 11));
	return (0);
}*/