#include "sort.h"

void lumo_sort(int *array, size_t size, int left, int right);
int lumo_part(int *array, size_t size, int left, int right);

/**
 * swap - Swap two values
 * @a: first to swap
 * @b: second to swap
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lumo_sort - Sorts through the quicksort algorithm
 * @array: An array of ints
 * @size: size of the array
 * @left: starting index of array
 * @right: ending index of the array
 */

void lumo_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lumo_part(array, size, left, right);
		lumo_sort(array, size, left, part - 1);
		lumo_sort(array, size, part + 1, right);
	}
}

/**
 * lumo_part - Partitions through quicksort
 * @array: the array to part
 * @size: the size of the array
 * @left: starting index of the array
 * @right: ending index of the array
 */

int lumo_part(int *array, size_t size, int left, int right)
{
	int *pivot, up, down;

	pivot = array + right;

	for (up = down = left; down < right; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				swap(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}
	if (array[up] > *pivot)
	{
		swap(array + up, pivot);
		print_array(array, size);
	}

	return (up);
}

/**
 * quick_sort - Sorts the array in ascending order
 * @array: The array to sort
 * @size: The size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lumo_sort(array, size, 0, size - 1);
}
