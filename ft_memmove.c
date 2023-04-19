/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:55:23 by joaocard          #+#    #+#             */
/*   Updated: 2023/03/14 14:30:48 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *destination, const void *source, size_t b)
{
	size_t	bytes;

	bytes = 0;
	if (!destination && !source)
		return (NULL);
	if (destination < source)
	{
		while (bytes < b)
		{
			*(char *)(destination + bytes) = *(char *) \
													(source + bytes);
			bytes++;
		}
	}
	else
	{
		bytes = b;
		while (bytes > 0)
		{
			*(char *)(destination + bytes) = *(char *) \
													(source + bytes);
			bytes--;
		}
	}
	return (destination);
}
