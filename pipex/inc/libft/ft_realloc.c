/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:20:28 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/26 16:37:06 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t original_size, size_t new_size)
{
	void	*result;
	size_t	i;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (!ptr)
		return (malloc(new_size));
	else
	{
		result = malloc(new_size);
		if (result)
		{
			if (original_size < new_size)
				i = original_size;
			else
				i = new_size;
			ft_memcpy(result, ptr, i);
			free(ptr);
		}
		return (result);
	}
}
