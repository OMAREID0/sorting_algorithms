#include "sort.h"

/**
 * selection_sort - Sort an array of integers in ascending order
 * using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, k;
    for(i = 0; i < size - 1; i++)
    {
        for(j = i = k ; j < size ; j++)
        {
            if(array[j] < array [k])
                k = j;
        }
        swap(array[i], array[k]);
        print_array(array, size);
    }
}