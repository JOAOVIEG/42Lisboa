/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:24:28 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/02 00:32:06 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	subs_count(char const *s, unsigned int start, size_t len)
{
	size_t	count;

	count = 0;
	s += start;
	while (*s++ && count < len)
		count++;
	return (count);
}

static char	*memory_check(void)
{
	char	*string;

	string = (char *)malloc((sizeof(char) * 1));
	if (!string)
		return (0);
	string[0] = '\0';
	return (string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	int					subslen;
	char				*subs;

	i = 0;
	if (start > ft_strlen(s))
		return (memory_check());
	subslen = subs_count(s, start, len);
	subs = (char *)malloc((sizeof(char) * subslen) + 1);
	if (!subs)
		return (0);
	s += start;
	while (*s && i < len)
	{
		subs[i] = *s++;
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

/*int main()
{
    char    *s = "Hello World. Good Morning";
    unsigned int    start = 589;
    printf("Should Be Good: %s\n", ft_substr(s, start, 0));
    return (0);
}*/