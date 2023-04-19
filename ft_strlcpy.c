/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:32:37 by joaocard          #+#    #+#             */
/*   Updated: 2023/04/19 15:52:11 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char		*ptr_dest;
	int			src_len;
	size_t		dest_counter;

	dest_counter = 0;
	src_len = 0;
	ptr_dest = dest;
	while (src[src_len])
	{
		src_len++;
	}
	while (dest_counter < (size - 1) && *src)
	{
		*ptr_dest++ = *src++;
		dest_counter++;
	}
	*ptr_dest = 0;
	return (src_len);
}

/*int	main()
{
	char dest[] = "Hello";
	char src[]	= "World";

	printf("%ld\n", ft_strlcpy(dest, src, sizeof(char) * 4));
	printf("%s\n", dest);
	return (0);
}*/