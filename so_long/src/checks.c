/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:37:02 by joaocard          #+#    #+#             */
/*   Updated: 2023/10/12 11:46:19 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    check_file(char *file)
{
    if (!file)
    {
        printf("Error\nNo file\n");
        return ;
    }
    while (*file)
    {
        if (*file == '.')
        {
            if (*(file + 1) == 'b' && *(file + 2) == 'e' && *(file + 3) == 'r')
            {
                printf("File is .ber\n");
                return ;
            }
            else
            {
                printf("Error\nFile is not .ber\n");
                return ;
            }
        }
        file++;
    }
}

void    map_checks(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nFile not found\n");
		return ;
	}
	if (!is_rectangle(fd))
	{
		printf("Error\nMap is not a rectangle\n");
		return ;
	}
}