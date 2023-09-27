#include "sort.h"

/**
 * swap - Swaps two values
 * @a: first value
 * @b: second value
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap(array + i, min);
			print_array(array, size);
		}
	}
}
