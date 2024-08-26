// random.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"

int* generate_random_numbers(int min, int max, int count) {
    if (min > max || count > (max - min + 1)) {
        fprintf(stderr, "Invalid input: ensure that min <= max and count is within the valid range.\n");
        return NULL;
    }

    int range = max - min + 1;
    int* numbers = (int*)malloc(range * sizeof(int));
    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    // Fill the array with all numbers in the range
    for (int i = 0; i < range; i++) {
        numbers[i] = min + i;
    }

    // Shuffle the array and select the first 'count' numbers
    srand(time(NULL));
    for (int i = 0; i < range; i++) {
        int j = rand() % range;
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Allocate memory for the result and copy the first 'count' numbers
    int* result = (int*)malloc(count * sizeof(int));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(numbers);
        return NULL;
    }

    for (int i = 0; i < count; i++) {
        result[i] = numbers[i];
    }

    free(numbers);
    return result;
}
