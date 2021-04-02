#include <stdio.h>

#include "sorting.h"

void bubble_sort(
    void* array, int length, 
    size_t data_type_size, 
    int (*compare)(void*, void*), 
    void (*swap)(void*, void*))
{
    int last_unsorted_element_index = length - 1;

    int i, j;
    for (i = 0; i < length; ++i) 
    {
        // printf("---- i = %d\n", i);
        for (j = 0; j < last_unsorted_element_index; ++j) 
        {
            // printf("j = %d: ", j);
            if (compare(array + j * data_type_size, array + j * data_type_size + data_type_size) > 0)
            {
                // printf("Swap!!!\n");
                swap(array + j * data_type_size, array + j * data_type_size + data_type_size);
            }
        }

        last_unsorted_element_index--;
    }
}