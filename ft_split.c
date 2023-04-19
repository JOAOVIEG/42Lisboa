/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:56:03 by joaocard          #+#    #+#             */
/*   Updated: 2023/04/17 14:44:25 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_index(char const *s, char c)
{
	size_t	i;
	size_t	index;

	i = 0;
	while (*s)
	{
		if (*s == c && (*(s + 1) != c || *(s + 1) == 0))
			i++;
		s++;
	}
	index = i + 1;
	return (index);
}

static char	*get_word(char const *s, int i0_word, int in_word, int len)
{
	char		*word;
	int			i_word;

	i_word = 0;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i0_word < in_word)
		word[i_word++] = s[i0_word++];
	word[i_word] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i_array;
	int		i0_word;
	int		in_word;

	array = (char **)malloc(sizeof(char *) * get_index(s, c));
	i_array = 0;
	i0_word = 0;
	if (!array)
		return (NULL);
	while (s[i0_word])
	{
		if (s[i0_word] != c && s[i0_word] != 0)
		{
			in_word = i0_word;
			while (s[in_word] != c && s[in_word])
				in_word++;
			array[i_array++] = get_word(s, i0_word, in_word, \
										(in_word - i0_word));
			i0_word = in_word;
		}
		i0_word++;
	}
	array[i_array] = 0;
	return (array);
}

/*int main ()
{
    char    *s = "CCCHello C You C How are youC";
    char    c = 'C';

    printf("Index 0: %s;\nIndex 1: %s;\nIndex 2: %s;\n", \
	 ft_split(s, c)[0], ft_split(s, c)[1], ft_split(s, c)[2]);
}*/