#include "sort.h"


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
            }
        }
    }
    print_array(array, size);
}