/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:10:56 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/02 00:31:58 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*THIS IS FOR TESTING. tO COMPILE W/OUT FLAGS.
char	test_tolower(unsigned int i, char chr)
{
	if (chr >= 'A' && chr <= 'Z')
		return (chr + 32);
	return (chr);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*itestr;
	int		index;

	itestr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	index = 0;
	if (!itestr)
		return (NULL);
	while ((size_t)(index) < ft_strlen(s))
	{
		*(itestr + index) = (*f)(index, *(s + index));
		index++;
	}
	*(itestr + index) = 0;
	return (itestr);
}

/*int main()
{
	char	*name = "JOAO VIEGAS";
	printf("%s\n", ft_strmapi(name, test_tolower));
	return 0;
}*/