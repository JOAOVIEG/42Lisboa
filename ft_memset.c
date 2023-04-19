/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:24:31 by joaocard          #+#    #+#             */
/*   Updated: 2023/03/09 11:14:39 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	bytes;

	bytes = 0;
	while (bytes < n)
	{
		*(unsigned char *)(s + bytes) = (unsigned char) c;
		bytes++;
	}
	return (s);
}
