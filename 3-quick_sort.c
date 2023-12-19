#include "sort.h"
/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partitioner - slices the array into lesser and greater and pivot.
 * @arr: the array to be partitioned.
 * @low: the begininf of the array `arr`.
 * @high: the last element in the array `arr`.
 *
 * Returns: the pivot index `i + 1`.
 */

int partitioner(int *arr, int low, int high)
{
	int i, j, pivot;

	i = low - 1;
	pivot = arr[high];
	for (j = low, j <= high - 1; ++j)
	{
		if (arr[j] < pivot)
			swap(&arr[j], &arr[++i]);
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1); /*index of pivot in its end place###*/
}

/**
 * quick_sort - sorts an array of integers in ascending order.
 * using the Quick sort algorithm(recursively).
 * @size: size of the array.
 *
 * Returns: void.
 */
void quick_sort(int *array, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = int partitioner(int *arr, 0, size - 1);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}