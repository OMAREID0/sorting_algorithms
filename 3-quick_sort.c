#include "sort.h"
#include <stdio.h>

/**
 * lomuto_partition - partitions subarray of `array` around pivot using
 * Lomuto method (always choose right element).
 * @array: array to partition
 * @low: left end of subarray
 * @high: right end of subarray
 * @size: size of array
 *
 * Return: index of pivot after it has been sorted
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int i, j, tmp, pivot;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i == j)
				continue;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	if (array[high] <= array[i + 1])
	{
		i++;
		if (i == high)
			return (i);
		tmp = array[i];
		array[i] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * _lomuto_quick_sort - recursively partitions array until it is fully sorted
 * @array: array to sort
 * @low: left side of subarray for recursion
 * @high: right side of subarray for recursion
 * @size: size of array
 */
void _lomuto_quick_sort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		_lomuto_quick_sort(array, low, p - 1, size);
		_lomuto_quick_sort(array, p + 1, high, size);
	}
}

/**
 * quick_sort - wrapper around recursive quicksort function
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	_lomuto_quick_sort(array, 0, size - 1, size);
}
