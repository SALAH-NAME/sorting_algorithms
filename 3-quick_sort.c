#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}

/**
 * quick_sort_rec - Recursively sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @start: The starting index of the sub-array to sort
 * @end: The ending index of the sub-array to sort
 * @size: Number of elements in @array
 */
void quick_sort_rec(int *array, ssize_t start, ssize_t end, size_t size)
{
	ssize_t pivot;

	if (start < end)
	{
		pivot = partition(array, start, end, size);
		quick_sort_rec(array, start, pivot - 1, size);
		quick_sort_rec(array, pivot + 1, end, size);
	}
}

/**
 * partition - Partitions a sub-array using the Lomuto partition scheme
 *
 * @array: The array to be partitioned
 * @start: The starting index of the sub-array to partition
 * @end: The ending index of the sub-array to partition
 * @size: Number of elements in @array
 *
 * Return: The final partition index
 */
ssize_t partition(int *array, ssize_t start, ssize_t end, size_t size)
{
	int pivot = array[end];
	ssize_t i = start;
	ssize_t j;
	int temp;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != end)
	{
		temp = array[i];
		array[i] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
	return (i);
}
