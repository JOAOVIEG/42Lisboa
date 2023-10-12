/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:15:12 by joaocard          #+#    #+#             */
/*   Updated: 2023/10/12 14:41:44 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_rectangle(int fd)
{
	char	*line;
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = 0;
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd);
		if (i == 0)
			j = ft_strlen(line);
		else if (j != ft_strlen(line))
			return (0);
		i++;
	}
	return (1);
}