/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:56:03 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/02 00:31:49 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	index_count(char const *s, char c)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			index++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (index);
}

static int	word_len(char const *s, char c, int i)
{
	while (*(s + i) && *(s + i) != c)
	{
		i++;
	}
	return (i);
}

static void	get_array_elements(char **array, char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = word_len(s, c, i);
			*array = ft_calloc(sizeof(**array), len - i + 1);
			if (!*array)
				return ;
			ft_memcpy(*array, s + i, len - i);
			array++;
			i = len - 1;
		}
		i++;
	}
	return ;
}

static char	**free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (NULL);
	while (*(array + i))
	{
		free(*(array + i));
		*(array + i) = NULL;
		i++;
	}
	free (array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s || s == NULL)
		return (NULL);
	array = ft_calloc(sizeof(*array), index_count(s, c) + 1);
	if (!array)
		return (NULL);
	get_array_elements(array, s, c);
	if (!array)
		return (free_array(array));
	return (array);
}

/*int main ()
{
	int	i = 0;
	int index = 4;
    char    *case0 = "CCCHello C You C How are youC";
	char	del0 = 'C';

    char	*case1 = "Hello";
	char 	del1 = 'C'; //no character found

	char	*case2 = "		 Hello	World";
	char	del2 = '	';//tab

	char	*case3 = "Hello World. Good Morning";
	char	del3 = '.';//dot

	char	*case4 = "Hello World";
	char	del4 = ' ';//space

	char 	**c0 = ft_split(case0, del0);
	char 	**c1 = ft_split(case1, del1);
	char 	**c2 = ft_split(case2, del2);
	char 	**c3 = ft_split(case3, del3);
	char 	**c4 = ft_split(case4, del4);
	while(i < index - 1)
	{
		printf("%s\n", c0[i]);
		++i;
	}
	return (0);
}*/