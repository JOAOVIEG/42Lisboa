/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:22:06 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/30 02:13:29 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static int bytes_read = 0;
    static int eof = 0;
    char *line = NULL;
    int line_length = 0;
    int line_capacity = 0;
    if (eof && bytes_read == 0)
        return NULL;
    while (1) {
        if (bytes_read == 0) {
            line = read_line(fd, buffer, &bytes_read, &eof);
            if (line == NULL)
                return NULL;
            if (eof)
                break ;
        }
        line = buffer_process(buffer, bytes_read, &line_length, &line_capacity);
        if (line != NULL) {
            line = resize_line_buffer(line, line_length, bytes_read, &line_capacity);
            return line;
        }
        line = (char *)malloc((line_length + bytes_read) * sizeof(char));
        if (line == NULL)
            return NULL;
        for (int i = 0; i < bytes_read; i++) {
            line[line_length++] = buffer[i];
        }
        bytes_read = 0;
    }
    return NULL;
}

int main() {
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
}