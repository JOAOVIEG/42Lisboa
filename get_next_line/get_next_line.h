/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:22:11 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/23 23:08:23 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE	42

# include <unistd.h>
# include <stdlib.h>
# include<stdio.h>

char			*get_next_line(int fd);
//static ssize_t	*ft_read_fd(int fd);
#endif