#include <stdio.h>

#define MAX_CONSTRAINT 1000 + 5

int maximum(int value1, int value2) {
    return value1 > value2 ? value1 : value2;
}

int knapsack(int capacity, int number_of_items, int items_weights[MAX_CONSTRAINT], int items_values[MAX_CONSTRAINT]) {
    int values_matrix[MAX_CONSTRAINT][MAX_CONSTRAINT];

    int max_value = 0;

    int current_item, current_capacity;

    // First item, number 0
    printf("========== Item 0: weight = %d, value = %d ==========\n", items_weights[0], items_values[0]);

    for(current_capacity = 0; current_capacity <= capacity; ++current_capacity) {
        
        if(current_capacity < items_weights[0]) {
            max_value = 0;
        }
        else {
            max_value = items_values[0];
        }

        values_matrix[0][current_capacity] = max_value;

        printf("- Capacity %d: %d\n", current_capacity, max_value);
    }

    // Item number 1 to n - 1
    for(current_item = 1; current_item < number_of_items; ++current_item) {

        printf("========== Item %d: weight = %d, value = %d ==========\n", 
            current_item, items_weights[current_item], items_values[current_item]);
        
        for(current_capacity = 0; current_capacity <= capacity; current_capacity++) {
            
            if(current_capacity < items_weights[current_item]) {
                max_value = values_matrix[current_item - 1][current_capacity];
            }
            else {
                max_value = maximum(
                    values_matrix[current_item - 1][current_capacity], 
                    items_values[current_item] + values_matrix[current_item - 1][current_capacity - items_weights[current_item]]);
            }

            values_matrix[current_item][current_capacity] = max_value;

            printf("- Capacity %d: %d\n", current_capacity, max_value);
        }
    }

    return max_value;
}

int main() {
    int capacity = 50;
    int number_of_items = 3;
    int items_values[MAX_CONSTRAINT] = {60, 100, 120};
    int items_weights[MAX_CONSTRAINT] = {10, 20, 30};

    int max = knapsack(capacity, number_of_items, items_weights, items_values);

    printf("Result: %d", max);

    return 0;
}