#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, k;

    for (i = 0; i < size - 1; i++)
    {
        k = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[k])
                k = j;
        }
        if (k != i)
        {
            swap(&array[k], &array[i]);
            print_array(array, size);
        }
    }
}
