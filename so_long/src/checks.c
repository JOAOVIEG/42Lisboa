/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:37:02 by joaocard          #+#    #+#             */
/*   Updated: 2023/10/12 16:48:02 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    check_file(char *file)
{
    if (!file)
    {
        ft_printf("Error\nNo file\n");
        return ;
    }
    while (*file)
    {
        if (*file == '.')
        {
            if (*(file + 1) == 'b' && *(file + 2) == 'e' && *(file + 3) == 'r' && *(file + 4) == '\0')
            {
                return ;
            }
            else
            {
                ft_printf("Error\nFile is not .ber\n");
                return ;
            }
        }
        file++;
    }
}

void    map_checks(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFile not found\n");
		return ;
	}
	/*if (!is_rectangle(fd))
	{
		printf("Error\nMap is not a rectangle\n");
		return ;
	}*/
}