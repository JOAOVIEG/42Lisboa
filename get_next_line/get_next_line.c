/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:22:06 by joaocard          #+#    #+#             */
/*   Updated: 2023/05/23 23:12:48 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *get_next_line(int fd) {
    static char buffer[BUFFER_SIZE];
    static int bytes_read = 0;
    static int eof = 0;

    char *line = NULL;
    int line_length = 0;
    int line_capacity = 0;

    // If EOF has been reached, return NULL
    if (eof && bytes_read == 0)
        return NULL;

    while (1) {
        // If buffer is empty, read from file descriptor
        if (bytes_read == 0) {
            bytes_read = read(fd, buffer, BUFFER_SIZE);

            // If end of file is reached, set EOF flag
            if (bytes_read == 0) {
                eof = 1;
                break;
            }

            // If an error occurred, return NULL
            if (bytes_read < 0)
                return NULL;
        }

        // Process each character in the buffer
        for (int i = 0; i < bytes_read; i++) {
            // Check if newline character is found
            if (buffer[i] == '\n') {
                // Calculate the line length
                int line_len = line_length + i;

                // Allocate memory for the line
                char *new_line = (char *)malloc((line_len + 2) * sizeof(char));

                // Copy characters from buffer to line
                if (new_line != NULL) {
                    int j, k = 0;

                    for (j = 0; j <= i; j++) {
                        new_line[k] = buffer[j];
                        k++;
                    }

                    new_line[k] = '\0';

                    // Update the line and line capacity
                    line = new_line;
                    line_capacity = line_len + 2;
                }

                // Update the buffer
                bytes_read -= (i + 1);
                for (int j = 0; j < bytes_read; j++) {
                    buffer[j] = buffer[i + j + 1];
                }

                return line;
            }
        }

        // Resize the line buffer if needed
        if (line_length + bytes_read + 1 > line_capacity) {
            // Calculate the new line capacity
            int new_capacity = line_length + bytes_read + 1;

            // Allocate memory for the line
            char *new_line = (char *)malloc(new_capacity * sizeof(char));

            if (new_line != NULL) {
                // Copy characters from the previous line
                for (int j = 0; j < line_length; j++) {
                    new_line[j] = line[j];
                }

                // Free the previous line memory
                free(line);

                // Update the line and line capacity
                line = new_line;
                line_capacity = new_capacity;
            } else {
                // Memory allocation failed
                free(line);
                return NULL;
            }
        }

        // Copy characters from buffer to line
        for (int i = 0; i < bytes_read; i++) {
            line[line_length++] = buffer[i];
        }

        bytes_read = 0;
    }
}

int main() {
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
}