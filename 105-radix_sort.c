#include "sort.h"

/**
 * get_max - get the maximum value in an array of integers
 * @array: array of integers
 * @size: size of the array
 *
 * Return: maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * count_digits - counts the number of occurrences of each digit in the array
 * @array: array of integers
 * @size: size of the array
 * @exp: digit to sort by
 * @count: array to store the count of each digit
 */
void count_digits(int *array, size_t size, int exp, int *count)
{
	int i;

	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
}

/**
 * reorder_array - reorders the array based on the count of each digit
 * @array: array of integers
 * @size: size of the array
 * @exp: digit to sort by
 * @count: array containing the count of each digit
 */
void reorder_array(int *array, size_t size, int exp, int *count)
{
	int *output = malloc(sizeof(int) * size);
	int i;

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(output);
}

/**
 * counting_sort_radix - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: array of integers
 * @size: size of the array
 * @exp: digit to sort by
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int count[10] = {0};

	count_digits(array, size, exp, count);
	reorder_array(array, size, exp, count);
}

/**
 * radix_sort - sorts an array of integers in ascending
 * order using the Radix sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int exp;

	if (array == NULL || size < 2)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}
