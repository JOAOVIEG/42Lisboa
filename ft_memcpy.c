/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:57:14 by joaocard          #+#    #+#             */
/*   Updated: 2023/04/19 15:52:13 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *destination, const void *source, size_t b)
{
	size_t	bytes;

	bytes = 0;
	if (!destination && !source)
		return (NULL);
	while (bytes < b)
	{
		*(char *)(destination + bytes) = *(char *) \
													(source + bytes);
		bytes++;
	}
	return (destination);
}
