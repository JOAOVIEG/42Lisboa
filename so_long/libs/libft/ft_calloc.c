/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:07:38 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/02 00:31:12 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}

/*int main()
{
	int n = 4;

	int i = 0;
	int j = 2;
	int *a = (int *)ft_calloc(n, sizeof(n));

	while (i < n)
	{
		a[i] = j;
		printf("%d\n", a[i]);
		i++;
		j += 2;
	}
	free(a);
	
	return (0);
}*/