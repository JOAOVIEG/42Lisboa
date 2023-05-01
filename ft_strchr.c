/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:00:13 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/02 00:31:50 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int chr)
{
	while (*str)
	{
		if (*(char *)str == (unsigned char)chr)
			return ((char *)str);
		str++;
	}
	if (*(char *)str == (unsigned char)chr)
		return ((char *)str);
	return (NULL);
}

/*int	main(void)
{
	const char	*str = "Hello C H\0ow are yoC";
	
	printf("%s", ft_strchr(str, 'C'));
	printf("%s", strchr(str, 'C'));
	return 0;
}*/
