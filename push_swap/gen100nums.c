/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen100nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaocard <joaocard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:18:04 by joaocard          #+#    #+#             */
/*   Updated: 2023/10/02 12:32:06 by joaocard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Define the range for random integers
    int min = 1;
    int max = 100;
    int num_values = 100;

    if (max - min + 1 < num_values) {
        printf("Error: Not enough unique values in the specified range.\n");
        return 1;
    }

    // Create an array to store unique random integers
    int unique_values[num_values];

    // Generate unique random numbers
    for (int i = 0; i < num_values; i++) {
        int random_num;
        int is_unique;

        do {
            random_num = (rand() % (max - min + 1)) + min;
            is_unique = 1;

            // Check if the generated value is already in the array
            for (int j = 0; j < i; j++) {
                if (random_num == unique_values[j]) {
                    is_unique = 0;
                    break;
                }
            }
        } while (!is_unique);

        unique_values[i] = random_num;

        // Print the unique random integer
        printf("%d ", random_num);
    }
    return 0;
}
