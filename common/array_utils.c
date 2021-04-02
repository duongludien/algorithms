#include <stdio.h>

#include "array_utils.h"

void print_array(
    void* array, 
    int length, 
    size_t data_type_size, 
    void (*print)(void*))
{
    int i;
    for (i = 0; i < length; ++i)
    {
        print(array + i * data_type_size);
    }
}