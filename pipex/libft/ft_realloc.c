/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:20:28 by joaocard          #+#    #+#             */
/*   Updated: 2024/01/04 19:15:19 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	original_size;
	size_t	mem_content;

	if (size == 0)
	{
		if (ptr != NULL)
			free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(size));
	new_ptr = malloc(size);
	original_size = ft_strlen(ptr) + 1;
	if (original_size < size)
		mem_content = original_size;
	else
		mem_content = size;
	ft_memcpy(new_ptr, ptr, mem_content);
	free(ptr);
	return (new_ptr);
}
