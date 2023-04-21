/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:24:28 by joaocard          #+#    #+#             */
/*   Updated: 2023/04/21 15:37:07 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	int		i;
	size_t	slen;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen || len == 0)
	{
		subs = malloc(1);
		*subs = 0;
		return (subs);
	}
	else
	{
		if (len > slen)
			len = slen - start;
		subs = (char *)malloc(sizeof(char) * len + 1);
		if (!subs)
			return (NULL);
		while (i < (int)(len))
		{
			*(subs + i) = *(char *)(s + start + i);
			i++;
		}
		*(subs + i) = 0;
	}
	return (subs);
}

/*int main()
{
    char    *s = "Hello World. Good Morning";
    unsigned int    start = 13;
    printf("Should Be Good: %s\n", ft_substr(s, start, 4));
    return (0);
}*/