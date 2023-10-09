/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:57:14 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/02 00:31:37 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int main()
{
	char	*myname = "Joao Viegas";
	char	*dest = (char *)malloc(sizeof(char) * 11);
	ft_memcpy(dest, myname, sizeof(*dest) * 10);
	printf("%s\n", dest);
	return (0);
}*/