#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char product[2];
    int quantity;
} SupplyItem;

SupplyItem* optimize_supply_chain(SupplyItem* data, int size, int* new_size) {
    SupplyItem* processed_data = (SupplyItem*)malloc(size * sizeof(SupplyItem));
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (data[i].quantity > 0) {
            processed_data[index] = data[i];
            index++;
        }
    }
    *new_size = index;
    return processed_data;
}

void analyze_boundaries(SupplyItem* data, int size, int* min_quantity, int* max_quantity) {
    *min_quantity = INT_MAX;
    *max_quantity = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (data[i].quantity < *min_quantity) {
            *min_quantity = data[i].quantity;
        }
        if (data[i].quantity > *max_quantity) {
            *max_quantity = data[i].quantity;
        }
    }
}

void main() {
    SupplyItem supply_data[] = {{"A", 10}, {"B", 0}, {"C", 25}};
    int size = sizeof(supply_data) / sizeof(supply_data[0]);
    int new_size;
    SupplyItem* optimized_data = optimize_supply_chain(supply_data, size, &new_size);
    int min_q, max_q;
    analyze_boundaries(optimized_data, new_size, &min_q, &max_q);
    printf("Minimum Quantity: %d, Maximum Quantity: %d\n", min_q, max_q);
    free(optimized_data);
}