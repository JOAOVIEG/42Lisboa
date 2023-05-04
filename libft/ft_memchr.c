/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:57:03 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/02 00:31:29 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int chr, size_t b)
{
	size_t	i;

	i = 0;
	while (i < b)
	{
		if (*(unsigned char *)(str + i) == (unsigned char) chr)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}

/*int main()
{
	char	*finda = "Good Morning ma neighbours!!";
	char *a = ft_memchr(finda, 'a', 20);
	printf("%c\n", *a);
	return(0);
}*/