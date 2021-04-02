#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

void print_array(
    void* array, 
    int length, 
    size_t data_type_size, 
    void (*print)(void*));

#endif