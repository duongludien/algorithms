#include <stdio.h>

#include "common/int_utils.h"
#include "common/array_utils.h"
#include "common/sorting.h"

int main(int argc, char const *argv[])
{
    int length = 10;
    int array[] = {4, 2, 6, 1, 5, 3, 9, -2, -6, -8};

    printf("Given: ");
    print_array(array, length, sizeof(int), print_int);
    printf("\n");

    bubble_sort(array, length, sizeof(int), compare_int, swap_int);

    printf("Result: ");
    print_array(array, length, sizeof(int), print_int);
    printf("\n");

    return 0;
}
