#include <stdio.h>

#define MAX_CONSTRAINT 1000 + 5

int knapsack(int capacity, int number_of_items, int items_weights[MAX_CONSTRAINT], int items_values[MAX_CONSTRAINT]) {
    int values_matrix[MAX_CONSTRAINT][MAX_CONSTRAINT];
    int quantities_matrix[MAX_CONSTRAINT][MAX_CONSTRAINT];

    int optimised_value = 0;
    int optimised_quantity = 0;

    int current_item, current_capacity;

    // First item, number 0
    printf("========== Item 0: weight = %d, value = %d ==========\n", items_weights[0], items_values[0]);

    for(current_capacity = 0; current_capacity <= capacity; ++current_capacity) {
        
        if(current_capacity < items_weights[0]) {
            optimised_value = 0;
            optimised_quantity = 0;
        }
        else {
            optimised_value = (current_capacity / items_weights[0]) * items_values[0];
            optimised_quantity = current_capacity / items_weights[0];
        }

        values_matrix[0][current_capacity] = optimised_value;
        quantities_matrix[0][current_capacity] = optimised_quantity;

        printf("- Capacity %d: value = %d, quantity = %d\n", current_capacity, optimised_value, optimised_quantity);
    }

    // Item number 1 to n - 1
    for(current_item = 1; current_item < number_of_items; ++current_item) {

        printf("========== Item %d: weight = %d, value = %d ==========\n", 
            current_item, items_weights[current_item], items_values[current_item]);
        
        for(current_capacity = 0; current_capacity <= capacity; ++current_capacity) {
            
            if(current_capacity < items_weights[current_item]) {
                optimised_value = values_matrix[current_item - 1][current_capacity];
                optimised_quantity = 0;
            }
            else {
                optimised_value = values_matrix[current_item - 1][current_capacity];
                optimised_quantity = 0;

                int current_item_quantity;
                
                for(current_item_quantity = 1; 
                    current_item_quantity <= current_capacity / items_weights[current_item]; 
                    ++current_item_quantity) 
                {
                    int current_value = current_item_quantity * items_values[current_item] + values_matrix[current_item - 1][current_capacity - items_weights[current_item] * current_item_quantity];
                    
                    if(current_value > optimised_value) {
                        optimised_value = current_value;
                        optimised_quantity = current_item_quantity;
                    }
                }
            }

            values_matrix[current_item][current_capacity] = optimised_value;
            quantities_matrix[current_item][current_capacity] = optimised_quantity;

            printf("- Capacity %d: value = %d, quantity = %d\n", current_capacity, optimised_value, optimised_quantity);
        }
    }

    return optimised_value;
}

int main() {
    int capacity = 100;
    int number_of_items = 3;
    int items_values[MAX_CONSTRAINT] = {10, 30, 20};
    int items_weights[MAX_CONSTRAINT] = {5, 10, 15};

    int max = knapsack(capacity, number_of_items, items_weights, items_values);

    printf("Result: %d", max);

    return 0;
}