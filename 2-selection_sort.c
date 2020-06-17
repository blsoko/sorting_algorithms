#include "sort.h"

/**
 * selection_sort - Prints a list of integers
 *
 * @array: Unordered array
 * @size: size of the array
 *
 * Return - Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, current;
	int swap;

	for (i = 0; i < size - 1; i++)
	{
		current = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[current] > array[j])
				current = j;
		}
		if (current != i)
		{
			swap = array[i];
			array[i] = array[current];
			array[current] = swap;
			print_array(array, size);
		}
	}
}
