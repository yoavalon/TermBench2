#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int item_id;
    int quantity;
    double cost;
} SupplyItem;

SupplyItem* generate_supply_data(int num_items) {
    SupplyItem* data = (SupplyItem*)malloc(num_items * sizeof(SupplyItem));
    for (int i = 0; i < num_items; i++) {
        data[i].item_id = rand() % 1000 + 1;
        data[i].quantity = rand() % 91 + 10;
        data[i].cost = (double)(rand() % 151 + 500) / 10.0;
    }
    return data;
}

SupplyItem* optimize_supply_chain(SupplyItem* data, int num_items) {
    double total_cost = 0;
    for (int i = 0; i < num_items; i++) {
        total_cost += data[i].quantity * data[i].cost;
    }
    double average_cost = total_cost / num_items;
    int count = 0;
    for (int i = 0; i < num_items; i++) {
        if (data[i].cost <= average_cost) {
            count++;
        }
    }
    SupplyItem* optimized_data = (SupplyItem*)malloc(count * sizeof(SupplyItem));
    int j = 0;
    for (int i = 0; i < num_items; i++) {
        if (data[i].cost <= average_cost) {
            optimized_data[j] = data[i];
            j++;
        }
    }
    free(data);
    return optimized_data;
}

void main() {
    int num_items = 50;
    srand(time(0));
    SupplyItem* supply_data = generate_supply_data(num_items);
    SupplyItem* optimized_data = optimize_supply_chain(supply_data, num_items);
    printf("Optimized supply chain data: ");
    for (int i = 0; i < num_items / 2; i++) { // Assuming half of the items are optimized for simplicity
        printf("{item_id: %d, quantity: %d, cost: %.1f} ", optimized_data[i].item_id, optimized_data[i].quantity, optimized_data[i].cost);
    }
    printf("\n");
    free(optimized_data);
}