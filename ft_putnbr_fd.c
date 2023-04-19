/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:39:58 by joaocard          #+#    #+#             */
/*   Updated: 2023/04/18 13:10:45 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*nbr;
	int		i;

	i = n;
	if (i >= INT_MIN && i <= INT_MAX)
	{
		nbr = ft_itoa(i);
		write(fd, nbr, ft_strlen(nbr));
	}
}

/*int main()
{
	int n = -2147483648;
	int fd = 1;

	ft_putnbr_fd(n, fd);
	//write(1, "\n", 1);
}*/