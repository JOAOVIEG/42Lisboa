/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:29:04 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/02 00:31:53 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i1;
	int		i2;
	char	*s3;
	size_t	s3len;

	i1 = 0;
	i2 = 0;
	s3len = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * s3len + 1);
	if (!s3)
		return (NULL);
	while (i1 < (int)(ft_strlen(s1)))
	{
		*(s3 + i1) = *(char *)(s1 + i1);
		i1++;
	}
	while (i1 < (int)(s3len))
	{
		*(s3 + i1) = *(char *)(s2 + i2);
		i1++;
		i2++;
	}
	*(s3 + i1) = 0;
	return (s3);
}

/*int main()
{
    char    *s1 = "Hello World.";
	char    *s2 = " Good Morning";
    printf("%s\n", ft_strjoin(s1, s2));
    return (0);
}*/