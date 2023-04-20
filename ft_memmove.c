/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:55:23 by joaocard          #+#    #+#             */
/*   Updated: 2023/04/20 11:40:12 by joaocard         ###   ########.fr       */
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
