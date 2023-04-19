/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:57:54 by joaocard          #+#    #+#             */
/*   Updated: 2023/04/17 22:26:31 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		index;

	index = 0;
	if (s && f)
	{
		while ((size_t)(index) < ft_strlen(s))
		{
			(*f)(index, s);
			index++;
		}
	}
}
