/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:52:33 by joaocard          #+#    #+#             */
/*   Updated: 2023/04/19 16:12:49 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int str)
{
	if ((unsigned int)(str) >= 0 && (unsigned int)(str) <= 127)
		return ((unsigned int)(str));
	return (0);
}
