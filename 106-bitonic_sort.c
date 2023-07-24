#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps two integers in an array
 * @array: array of integers
 * @i: index of first integer to swap
 * @j: index of second integer to swap
 */
void swap(int *array, int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * bitonic_compare - compares and swaps elements in a bitonic sequence
 * @array: array of integers
 * @size: size of the array
 * @i: index of first element to compare
 * @j: index of second element to compare
 * @dir: direction to sort in (1 for ascending, 0 for descending)
 */
void bitonic_compare(int *array, size_t size, size_t i, size_t j, int dir)
{
	if (dir == (array[i] > array[j]))
	{
		swap(array, i, j);
		print_array(array, size);
	}
}

/**
 * bitonic_merge - recursively sorts a bitonic sequence in ascending order
 * @array: array of integers
 * @size: size of the array
 * @low: lowest index of the bitonic sequence to sort
 * @count: number of elements in the bitonic sequence to sort
 * @dir: direction to sort in (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, size_t low, size_t count, int dir)
{
	size_t i, k = count / 2;

	if (count < 2)
		return;
	for (i = low; i < low + k; i++)
		bitonic_compare(array, size, i, i + k, dir);
	bitonic_merge(array, size, low, k, dir);
	bitonic_merge(array, size, low + k, k, dir);
}

/**
 * bitonic_sort_rec - recursively sorts an array of integers in ascending
 * order using the Bitonic sort algorithm
 * @array: array of integers
 * @size: size of the array
 * @low: lowest index of the sub-array to sort
 * @count: number of elements in the sub-array to sort
 * @dir: direction to sort in (1 for ascending, 0 for descending)
 */
void bitonic_sort_rec(int *array, size_t size, size_t low, size_t count, int dir)
{
	size_t k = count / 2;

	if (count < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", count, size, dir ? "UP" : "DOWN");
	print_array(array + low, count);
	bitonic_sort_rec(array, size, low, k, 1);
	bitonic_sort_rec(array, size, low + k, k, 0);
	bitonic_merge(array, size, low, count, dir);
}

/**
 * bitonic_sort - sorts an array of integers in ascending
 * order using the Bitonic sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_sort_rec(array, size, 0, size, 1);
}
