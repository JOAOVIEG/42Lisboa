/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:24:31 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/02 00:31:43 by joaocard         ###   ########.fr       */
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

/*int main()
{
    char s[3];
    int i;
    
    ft_memset(s, 'o', sizeof(char) * 3);
    i = 0;
    while(i < 3)
    {
        printf("%c", s[i]);
        i++;
    }
    printf("\n");
}*/