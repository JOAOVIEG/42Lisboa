/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:22:06 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/31 15:22:14 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 0)
	{
		set_buffer_zero(buffer);
		return (NULL);
	}
	while (*buffer != 0 || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = buffer_to_line_process(line, buffer);
		if (ft_buffer_shift(buffer))
			break ;
	}
	return (line);
}

/*int main() {
    FILE *file = fopen("sample.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fileno(file))) != NULL) {
        printf("%s\n", line);
        free(line);
    }

    fclose(file);

    return 0;
}*/