/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:47:59 by joaocard          #+#    #+#             */
/*   Updated: 2023/04/05 13:29:38 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	int	len;

	len = ft_strlen(str);
	str = str + len - 1;
	while (*str--)
	{
		if (*str == (char) chr)
			return ((char *) str);
	}
	return (NULL);
}
