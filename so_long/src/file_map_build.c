/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map_build.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:37:02 by joaocard          #+#    #+#             */
/*   Updated: 2023/10/26 14:59:38 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int    check_file_ext(char *file)
{
    if (!file)
    {
        ft_printf("Error\nNo file\n");
        return (EXIT_FAILURE);
    }
	else
	{
		while (*file)
    	{
        	if (*file == '.')
        	{
            	if (*(file + 1) == 'b' && *(file + 2) == 'e' && *(file + 3) == 'r' && *(file + 4) == '\0')
                	return (EXIT_SUCCESS);
            	else
            	{
                	ft_printf("Error\nFile is not .ber\n");
                	return (EXIT_FAILURE);
            	}
        	}
        	file++;
    	}
	}
	return (0);
}

void    file_map_build(char *file, t_game *game)
{
    int fd;
    
    check_file_ext(file);
    fd = open(file, O_RDONLY);
    map_read(fd, game);
}