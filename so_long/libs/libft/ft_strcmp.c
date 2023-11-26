/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:37:30 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/26 16:21:20 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *sc1, const char *sc2)
{
	while (*sc1 || *sc2)
	{
		if ((unsigned char)*sc1 != (unsigned char)*sc2)
			return ((unsigned char)*sc1 - (unsigned char)*sc2);
		sc1++;
		sc2++;
	}
	return (0);
}
