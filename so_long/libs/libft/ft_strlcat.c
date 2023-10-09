/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:48:08 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/02 00:31:55 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *source, size_t	size_of_str)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(source);
	if (size_of_str <= dest_len)
		return (src_len + size_of_str);
	dest = dest + dest_len;
	while (*source && i < (size_of_str - dest_len - 1))
	{
		*dest++ = *source++;
		i++;
	}
	*dest = 0;
	return (dest_len + src_len);
}

/*int	main()
{
	char *dest = "Hello";
	char *src	= "World";

	printf("%ld\n", ft_strlcat(dest, src, 2));
	printf("%s\n", dest);
	return (0);
}*/