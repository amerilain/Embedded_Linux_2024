#include <stdio.h>
#include <stdlib.h>
#include "random.h"

int main(int argc, char* argv[]) {
    int min, max, count;

    // Check if command line arguments are provided
    if (argc == 4) {
        min = atoi(argv[1]);
        max = atoi(argv[2]);
        count = atoi(argv[3]);
    } else {
        // Prompt the user for input if no arguments are provided
        printf("Enter minimum value: ");
        scanf("%d", &min);
        printf("Enter maximum value: ");
        scanf("%d", &max);
        printf("Enter count of unique random numbers to generate: ");
        scanf("%d", &count);
    }

    // Call the function to generate random numbers
    int* random_numbers = generate_random_numbers(min, max, count);

    // Output the generated numbers
    if (random_numbers != NULL) {
        printf("Generated random numbers: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", random_numbers[i]);
        }
        printf("\n");

        // Free the allocated memory
        free(random_numbers);
    }

    return 0;
}
