/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:16:09 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/02 00:31:10 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	bytes;

	bytes = 0;
	while (bytes < n)
	{
		*(char *)(s + bytes) = 0;
		bytes++;
	}
}

/*int main()
{
	//int number = 42;
	char name = 'J';
	ft_bzero(&name, sizeof(name));
	printf("%d\n", name);
	return (0);
}*/
