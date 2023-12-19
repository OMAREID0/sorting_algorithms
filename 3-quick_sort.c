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
 * @low: the beginning of the array `arr`.
 * @high: the last element in the array `arr`.
 * @size: size of the array
 *
 * Returns: the pivot index `i + 1`.
 */
int partitioner(int *arr, int low, int high, size_t size)
{
        int i, j, pivot;

        i = low - 1;
        pivot = arr[high];
        for (j = low; j <= high - 1; ++j)
        {
                if (arr[j] < pivot)
                {
                        swap(&arr[j], &arr[++i]);
                }
        }
        swap(&arr[i + 1], &arr[high]);
        print_array(arr, size);
        return (i + 1);
}

/**
 * lomuto_scheme - Lomuto partition scheme for QuickSort
 * @arr: the array to be sorted
 * @low: the beginning of the array
 * @high: the last element in the array
 * @size: size of the array
 *
 * Returns: void
 */
void lomuto_scheme(int *arr, int low, int high, size_t size)
{
        int pi;

        if (low < high)
        {
                pi = partitioner(arr, low, high, size);
                lomuto_scheme(arr, low, pi - 1, size);
                lomuto_scheme(arr, pi + 1, high, size);
        }
}

/**
 * quick_sort - sorts an array of integers in ascending order.
 * using the Quick sort algorithm(recursively).
 * @array: the array to be sorted
 * @size: size of the array
 *
 * Returns: void
 */
void quick_sort(int *array, size_t size)
{
	lomuto_scheme(array, 0, size - 1, size);
}
