/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:55:23 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/02 00:31:42 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *destination, const void *source, size_t b)
{
	char	*dest;
	char	*src;

	dest = (char *)(destination);
	src = (char *)(source);
	if (!dest && !src)
		return (NULL);
	if (destination == source)
		return (destination);
	if (destination < source)
		ft_memcpy(dest, src, b);
	else
		while (b--)
			*(dest + b) = *(src + b);
	return ((void *)dest);
}

/*int main()
{
	char	*name = "Joao Viegas";
	char	*move = "Joaso";
	ft_memmove((void *)&name, (void *)&move, 11);
	printf("%s\n", name);
	return (0);
}*/