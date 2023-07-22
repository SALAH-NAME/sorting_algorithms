#include "sort.h"

/**
 * find_max - Finds the maximum value in an array of integers
 *
 * @array: The array to search
 * @size: The size of the array
 *
 * Return: The maximum value in the array
 */
int find_max(int *array, size_t size)
{
	int max, i;

	max = array[0];
	for (i = 1; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

/**
 * count_values - Counts the occurrences of each value in an array of integers
 *
 * @array: The array to count
 * @size: The size of the array
 * @max: The maximum value in the array
 *
 * Return: An array of counts, where the value at index i is the number of
 * occurrences of the value i in the input array
 */
int *count_values(int *array, size_t size, int max)
{
	int *count, i;

	count = malloc(sizeof(int) * (max + 1));
	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	return (count);
}

/**
 * calculate_cumulative_counts - Calculates the cumulative counts for an array
 * of counts
 *
 * @count: The array of counts
 * @max: The maximum value in the input array
 */
void calculate_cumulative_counts(int *count, int max)
{
	int i;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
}

/**
 * build_output - Builds the output array for counting sort
 *
 * @array: The input array to sort
 * @size: The size of the input array
 * @count: The array of cumulative counts
 *
 * Return: The sorted output array
 */
int *build_output(int *array, size_t size, int *count)
{
	int i;
	int *output;

	output = malloc(sizeof(int) * size);
	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	return (output);
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	int max, j;
	int *count, *output;

	if (array == NULL || size < 2)
		return;

	max = find_max(array, size);
	count = count_values(array, size, max);
	calculate_cumulative_counts(count, max);

	print_array(count, max + 1);

	output = build_output(array, size, count);

	for (j = 0; j < (int)size; j++)
		array[j] = output[j];

	free(count);
	free(output);
}
