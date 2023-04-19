/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:00:13 by joaocard          #+#    #+#             */
/*   Updated: 2023/04/19 10:24:02 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int chr)
{
	if (*str == 0)
		return (NULL);
	while (*(str++))
	{
		if (*str == (char) chr)
			return ((char *) str);
	}
	return ((char *) str);
}

/*int	main(void)
{
	const char	*str = "Hello C How are yoC";
	
	printf("%s", ft_strchr(str, 'C'));
	printf("%s", strchr(str, 'C'));
	return 0;
}*/
