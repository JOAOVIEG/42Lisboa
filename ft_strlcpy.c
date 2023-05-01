/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:32:37 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/02 00:31:56 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t		src_c;

	src_c = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (src_c < (size - 1) && *(src + src_c))
	{
		*(dest + src_c) = *(src + src_c);
		src_c++;
	}
	*(dest + src_c) = '\0';
	while (*(src + src_c))
	{
		src_c++;
	}
	return (ft_strlen(src));
}

/*int	main()
{
	char dest[] = "Hello";
	char src[]	= "World";

	printf("%ld\n", ft_strlcpy(dest, src, sizeof(char) * 4));
	printf("%s\n", dest);
	return (0);
}*/