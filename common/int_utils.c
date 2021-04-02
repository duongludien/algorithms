#include <stdio.h>

#include "int_utils.h"

void swap_int(void* p1, void* p2)
{
    int tmp = *(int*) p1;
    *(int*) p1 = *(int*) p2;
    *(int*) p2 = tmp;
}

int compare_int(void* p1, void* p2)
{
    // printf("Compare %d and %d\n", *(int*) p1, *(int*) p2);
    if (*(int*) p1 > *(int*) p2) return 1;
    if (*(int*) p1 > *(int*) p2) return -1;
    return 0;
}

void print_int(void* p)
{
    printf("%d ", *(int*)p);
}