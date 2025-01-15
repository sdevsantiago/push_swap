#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RED "\033[1;31m"
#define RESET "\033[0m"

int main(int argc, char const *argv[])
{
	// Control the number of arguments
	if (argc != 2) {
		printf(RED "❌ Usage: %s <number_of_elements>\n" RESET, argv[0]);
		return (EXIT_FAILURE);
	}

	// Convert the argument to an integer
	int n = atoi(argv[1]);
	if (n <= 0) {
		printf(RED "❌ The number of elements must be a positive integer\n" RESET);
		return (EXIT_FAILURE);
	}

	// Create an array to store the numbers
	int *numbers = malloc(n * sizeof(int));
	if (numbers == NULL) {
		printf(RED "❌ Memory allocation failed\n" RESET);
		return (EXIT_FAILURE);
	}

	// Generate unique numbers in the range [-n, n]
	int range = 2 * n + 1;
	int *all_numbers = malloc(range * sizeof(int));
	if (all_numbers == NULL) {
		printf(RED "❌ Memory allocation failed\n" RESET);
		free(numbers);
		return (EXIT_FAILURE);
	}

	for (int i = 0; i < range; i++) {
		all_numbers[i] = i - n;
	}

	// Shuffle the numbers using the Fisher-Yates algorithm
	srand(time(NULL));
	for (int i = range - 1; i > 0; i--) {
	    int j = rand() % (i + 1);
	    int temp = all_numbers[i];
	    all_numbers[i] = all_numbers[j];
	    all_numbers[j] = temp;
	}

	// Select the first n numbers from the shuffled array
	for (int i = 0; i < n; i++) {
	    numbers[i] = all_numbers[i];
	}

	// Create a string to store the numbers
	char *numbers_str = malloc(n * 12 * sizeof(char)); // Assuming each number has at most 12 digits
	if (numbers_str == NULL) {
	    printf(RED "❌ Memory allocation failed\n" RESET);
	    free(numbers);
	    free(all_numbers);
	    return (EXIT_FAILURE);
	}
	numbers_str[0] = '\0';

	// Concatenate the numbers into the string
	for (int i = 0; i < n; i++) {
	    char num_str[12];
	    sprintf(num_str, "%d ", numbers[i]);
	    strcat(numbers_str, num_str);
	}

	// Print the shuffled numbers
	for (int i = 0; i < n; i++) {
	    printf("%d ", numbers[i]);
	}
	printf("\n");

	// Free the allocated memory
	free(numbers);
	free(all_numbers);
	free(numbers_str);

	return (EXIT_SUCCESS);
}