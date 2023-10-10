/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:45:27 by joaocard          #+#    #+#             */
/*   Updated: 2023/10/10 13:50:20 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


int	main(int ac, char **av)
{
	if (ac != 2)
    {
        printf("Error\nWrong number of arguments\n");
        return (1);
    }
    if (ac ==2)
    {
        check_file(av[1]);
        map_checks(av[1]);
    }
}