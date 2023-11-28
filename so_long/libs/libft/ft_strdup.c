/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:08:31 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/28 10:43:06 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strdup(const char *string)
{
	int		i;
	char	*ptr;
	size_t	stringlen;

	i = 0;
	stringlen = ft_strlen(string);
	ptr = (char *)malloc(sizeof(char) * stringlen + 1);
	if (!ptr)
		return (NULL);
	while (i < (int)(stringlen + 1))
	{
		*(ptr + i) = *(char *)(string + i);
		i++;
	}
	return (ptr);
}

/*int main()
{
	char	*string = "Hello World!";
	printf("ft_strdup: %s\n", ft_strdup(string));
	printf("strdup: %s\n", strdup(string));
}*/
