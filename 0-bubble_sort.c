#include "sort.h"

/**
 * bubble_sort - Prints a list of integers
 *
 * @array: Unordered array
 * @size: size of the array
 *
 * Return - Nothing
 */
void bubble_sort(int *array, size_t size)
{
	int temp = 0, i, j;

	for (i = size - 2; i >= 0; i--)
	{
		for (j = 0; j <= i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
