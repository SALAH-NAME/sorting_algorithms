#include <stdio.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of integers
 *
 * @array: The array containing the subarrays to merge
 * @left: The left subarray to merge
 * @right: The right subarray to merge
 * @size: The size of the array
 */
void merge(int *array, int *left, int *right, size_t size)
{
	int i, j, k;
	int size_l, size_r;

	/* Calculate the sizes of the left and right subarrays */
	size_l = size / 2;
	size_r = size - size_l;

	/* Print the left and right subarrays */
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_l);
	printf("[right]: ");
	print_array(right, size_r);

	/* Merge the left and right subarrays into the output array */
	i = j = k = 0;
	while (i < size_l && j < size_r)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}
	while (i < size_l)
		array[k++] = left[i++];
	while (j < size_r)
		array[k++] = right[j++];

	/* Print the merged output array */
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid, i;
	int left[300], right[300];

	/* Check for invalid inputs */
	if (array == NULL || size < 2)
		return;

	/* Calculate the midpoint of the array */
	mid = size / 2;

	/* Split the array into left and right subarrays */
	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	/* Recursively sort the left and right subarrays */
	merge_sort(left, mid);
	merge_sort(right, size - mid);

	/* Merge the sorted left and right subarrays */
	merge(array, left, right, size);
}
