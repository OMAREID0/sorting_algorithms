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
    int tmp;
    size_t i, j;

    if (array == NULL || size < 2)
        return;

    for (; i < size - 1; i++)
    {
	    for (j = 0; j < size - i - 1; j++)
	    {
		    if (array[j] > array[j + 1])
		    {
			    tmp = array[j + 1];
			    array[j + 1] = array[j];
			    array[j] = tmp;
			    print_array(array, size);
		    }
	    }
    }
}
