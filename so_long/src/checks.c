/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:37:02 by joaocard          #+#    #+#             */
/*   Updated: 2023/10/10 13:51:31 by joaocard         ###   ########.fr       */
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
    int     fd;
    char    *line;
    int     i;
    int     j;

    i = 0;
    j = 0;
    fd = open(file, O_RDONLY);
    while (get_next_line(fd, &line))
    {
        if (i == 0)
            j = ft_strlen(line);
        if (j != ft_strlen(line))
        {
            printf("Error\nMap is not rectangular\n");
            return ;
        }
        i++;
    }
    printf("Map is rectangular\n");
    close(fd);
}