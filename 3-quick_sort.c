#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: First integer.
 * @b: Second integer.
 * Return: Void.
 */
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * partitioner - Partitions the array into lesser and greater elements around the pivot.
 * @arr: The array to be partitioned.
 * @low: The beginning of the array.
 * @high: The last element in the array.
 * @size: Size of the array.
 *
 * Returns: The pivot index `i + 1`.
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
            print_array(arr, size);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    print_array(arr, size);

    return (i + 1);
}

/**
 * lomuto_scheme - Lomuto partition scheme for QuickSort.
 * @arr: The array to be sorted.
 * @low: The beginning of the array.
 * @high: The last element in the array.
 * @size: Size of the array.
 *
 * Returns: Void.
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
 * quick_sort - Sorts an array of integers in ascending order using the Quick sort algorithm.
 * @array: The array to be sorted.
 * @size: Size of the array.
 *
 * Returns: Void.
 */
void quick_sort(int *array, size_t size)
{
    lomuto_scheme(array, 0, size - 1, size);
}
