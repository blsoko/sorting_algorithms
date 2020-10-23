#include "sort.h"
/**
 * partition - divides each array in 2 by 2
 *
 * @array: head
 * @low: position low
 * @high: high of array
 * @size: size of array
 *
 * Return: the position of pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, tmp;

	pivot = array[high];
	for (j = low, i = low - 1; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[high])
	{
		tmp = array[high];
		array[high] = array[i + 1];
		array[i + 1] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * recursive_qs - recurisve function which call himself
 *
 * @array: head
 * @low: position low
 * @high: high of array
 * @size: size of array
 *
 * Return: nothing
 */
void recursive_qs(int *array, int low, int high, size_t size)
{
	int index;

	if (low < high)
	{
		index = partition(array, low, high, size);
		recursive_qs(array, low, index - 1, size);
		recursive_qs(array, index + 1, high, size);

	}
}
/**
 * quick_sort - check errors
 *
 * @array: head
 * @size: size of array
 *
 * Return: the position of pivot
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recursive_qs(array, 0, size - 1, size);
}
