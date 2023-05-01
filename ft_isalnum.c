/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:29:51 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/02 00:31:13 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*int main()
{s
	int alpha0 = '2';
	int alpha1 = 'a';
	int alpha2 = '"';
	
	printf("Returns 0 if false. Other if true: %d\n", ft_isalnum(alpha0));
	printf("Returns 0 if false. Other if true: %d\n", ft_isalnum(alpha1));
	printf("Returns 0 if false. Other if true: %d\n", ft_isalnum(alpha2));
	return (0);
}*/