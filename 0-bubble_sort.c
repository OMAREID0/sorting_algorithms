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
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: The array of integers to be sorted.
 * @size: The number of elements in the array.
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
        int *p, *q;

        if (array == NULL || size < 2)
        return;
        for (p = array; p < array + size - 1; p++)
        {
                for (q = array; q < array + size - 1; q++)
                {
                        if (*q > *(q + 1))
                        {
                                swap(q, q + 1);
                                print_array(array, size);
                        }
                }
        }
}
