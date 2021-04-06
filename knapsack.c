#include <stdio.h>

#define MAX_CONSTRAINT 1000 + 5

int maximum(int value1, int value2) {
    return value1 > value2 ? value1 : value2;
}

int knapsack(int capacity, int number_of_items, int items_weights[MAX_CONSTRAINT], int items_values[MAX_CONSTRAINT]) {
    int matrix[MAX_CONSTRAINT][MAX_CONSTRAINT];

    int max = 0;
    int current_item, current_capacity;

    // First item, number 0
    printf("========== Item 0: weight = %d, value = %d ==========\n", 
        items_weights[0], items_values[0]);

    for(current_capacity = 0; current_capacity <= capacity; ++current_capacity) {
        
        if(current_capacity < items_weights[0]) {
            max = 0;
            matrix[0][current_capacity] = 0;
        }
        else {
            max = items_values[0];
            matrix[0][current_capacity] = items_values[0];
        }

        printf("- Capacity %d: %d\n", current_capacity, max);
    }

    // Item number 1 to n - 1
    for(current_item = 1; current_item < number_of_items; ++current_item) {

        printf("========== Item %d: weight = %d, value = %d ==========\n", 
            current_item, items_weights[current_item], items_values[current_item]);
        
        for(current_capacity = 0; current_capacity <= capacity; current_capacity++) {
            
            if(current_capacity < items_weights[current_item]) {
                // printf("Get matrix[%d][%d] = %d\n", current_item - 1, current_capacity, matrix[current_item - 1][current_capacity]);
                max = matrix[current_item - 1][current_capacity];
                matrix[current_item][current_capacity] = matrix[current_item - 1][current_capacity];
            }
            else {
                max = maximum(
                    matrix[current_item - 1][current_capacity], 
                    items_values[current_item] + matrix[current_item - 1][current_capacity - items_weights[current_item]]);
                matrix[current_item][current_capacity] = max;
            }

            printf("- Capacity %d: %d\n", current_capacity, max);
        }
    }

    return max;
}

int main() {
    int capacity = 4;
    int number_of_items = 3;
    int items_values[MAX_CONSTRAINT] = {1, 2, 3};
    int items_weights[MAX_CONSTRAINT] = {4, 5, 1};

    int max = knapsack(capacity, number_of_items, items_weights, items_values);

    printf("Result: %d", max);

    return 0;
}