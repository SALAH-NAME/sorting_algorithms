#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Calculate the largest gap using the Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Perform shell sort using decreasing gaps */
	while (gap >= 1)
	{
		/* Perform insertion sort on sub-arrays defined by gap */
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j] < array[j - gap]; j -= gap)
			{
				temp = array[j];
				array[j] = array[j - gap];
				array[j - gap] = temp;
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}
