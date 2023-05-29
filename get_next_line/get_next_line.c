/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:22:06 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/29 19:17:53 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	bytes_read;
	static int	eof;
	char		*line;
	int			line_capacity;

	bytes_read = 0;
	eof = 0;
	line = NULL;
	line_capacity = 0;
	if (eof && bytes_read == 0)
		return (NULL);
	while (1)
	{
		bytes_read = read_bytes(fd, bytes_read, buffer[BUFFER_SIZE]);
		if (bytes_read == 0)
		{
			eof == 1;
			break ;
		}
		if (bytes_read < 0)
			return (NULL);
		line = buffer_c_process(bytes_read, buffer, line_capacity);
	}
}

/*int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    int fd = fileno(file);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
        free(line);
    }

    fclose(file);
    return 0;
}*/