/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:47:59 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/02 00:32:03 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	char	*lastc;

	lastc = 0;
	while (*(char *)str)
	{
		if (*(char *)str == (unsigned char)chr)
			lastc = (char *)str;
		str++;
	}
	if (*(char *)str == (unsigned char)chr)
		return ((char *)str);
	return (lastc);
}
/*int    main(void)
{
    const char    *str = "Hello C H\0Cow are yoC";
    
    printf("%s\n", ft_strrchr(str, '\0'));
    printf("%s\n", strrchr(str, '\0'));
    return 0;
}*/