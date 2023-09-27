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
 * shell_sort - Sort an array in ascending order
 * @array: the array to sort
 * @size: the size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap(array + j, array + (j - gap));
				j = j - gap;
			}
		}
		print_array(array, size);
	}
}
