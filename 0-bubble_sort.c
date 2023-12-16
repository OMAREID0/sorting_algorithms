#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
    int tmp, i, j;
    if (array == NULL || size == 0)
        return;
    for(i = 0 ; i < size ; i++)
    {
        for (j = 1 ; j < size ; i++)
        {
            if (array[i] > array[j])
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
            print_array(array, size);
        }
    }
}