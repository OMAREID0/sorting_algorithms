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
