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
 * lomuto_partition - Lomuto partition scheme for QuickSort
 * @array: the array to be sorted
 * @low: the beginning of the array
 * @high: the last element in the array
 * @size: size of the array
 *
 * Returns: pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
            print_array(array, size);
        }
    }

    swap(&array[i + 1], &array[high]);
    print_array(array, size);

    return (i + 1);
}

/**
 * lomuto_sort - recursive function to sort the array using Lomuto scheme
 * @array: the array to be sorted
 * @low: the beginning of the array
 * @high: the last element in the array
 * @size: size of the array
 *
 * Returns: void
 */
void lomuto_sort(int *array, int low, int high, size_t size)
{
    int pi;

    if (low < high)
    {
        pi = lomuto_partition(array, low, high, size);
        lomuto_sort(array, low, pi - 1, size);
        lomuto_sort(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - sorts an array of integers in ascending order.
 * using the Quick sort algorithm (recursively).
 * @array: the array to be sorted
 * @size: size of the array
 *
 * Returns: void
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_sort(array, 0, size - 1, size);
}
