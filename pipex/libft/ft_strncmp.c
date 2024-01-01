/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:25:14 by joaocard          #+#    #+#             */
/*   Updated: 2023/11/03 21:31:20 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *sn1, const char *sn2, size_t nb)
{
	size_t	i;

	i = 0;
	while (i++ < nb && (*sn1 || *sn2))
	{
		if ((unsigned char)*sn1 != (unsigned char)*sn2)
			return ((unsigned char)*sn1 - (unsigned char)*sn2);
		sn1++;
		sn2++;
	}
	return (0);
}

/*int main(void)
{
	char *s1 = "Joao";
	char *s2 = "Job";

	printf("%d\n", ft_strncmp(s1, s2, 2));
	printf("%d\n", strncmp(s1, s2, 2));
	//return 0;
}*/
