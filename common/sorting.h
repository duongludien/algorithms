#ifndef SORTING_H
#define SORTING_H

void bubble_sort(
    void* array, int length, 
    size_t data_type_size, 
    int (*compare)(void*, void*), 
    void (*swap)(void*, void*));

#endif