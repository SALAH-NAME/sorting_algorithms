#include "sort.h"

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
 * sift_down - repairs the heap whose root element is at index 'start'
 * @array: array of integers
 * @start: root index of heap to repair
 * @end: last index of heap to repair
 * @size: size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		if (child + 1 <= end && array[child] < array[child + 1])
			child++;
		if (array[root] < array[child])
		{
			swap(array, root, child);
			print_array(array, size);
			root = child;
		}
		else
			return;
	}
}

/**
 * heapify - creates a max heap from an unordered array
 * @array: array of integers
 * @size: size of the array
 */
void heapify(int *array, size_t size)
{
	int start = (size - 2) / 2;

	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order using the Heap sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int end = size - 1;

	if (array == NULL || size < 2)
		return;

	heapify(array, size);
	while (end > 0)
	{
		swap(array, end, 0);
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}
