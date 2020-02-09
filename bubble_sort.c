#include "push_swap.h"

void    bubble_sort(int *arr, int size)
{
    int i;
    int j;
    int sorted;

    i = 0;
    sorted = 1;
    while (i < size && sorted)
    {
        sorted = 0;
        j = i + 1;
        while (j < size)
        {
            if (arr[j] < arr[i])
            {
                swap(&arr[i], &arr[j]);
                sorted = 1;
            }
            j++;
        }
        i++;
    }
}