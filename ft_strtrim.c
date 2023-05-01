/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:56:54 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/02 00:32:04 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimedstr;
	size_t	end;
	int		start;
	int		i;

	end = ft_strlen(s1);
	start = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (*(char *)(s1 + start) && is_set(*(char *)(s1 + start), set))
		start++;
	while ((int)(end) > start && is_set(*(char *)(s1 + (int)(end - 1)), set))
		end--;
	trimedstr = (char *)malloc(sizeof(char) * (size_t)(end - start + 1));
	if (!trimedstr)
		return (NULL);
	while (start < (int)end)
	{
		*(trimedstr + i) = *(char *)(s1 + start);
		i++;
		start++;
	}
	*(trimedstr + i) = 0;
	return (trimedstr);
}

/*int main()
{
	char	*s1 = "Joao Viegas";
	char	*set = "Jas";
	printf("Trimmed should be oao Vieg: %s\n", ft_strtrim(s1, set));
}*/