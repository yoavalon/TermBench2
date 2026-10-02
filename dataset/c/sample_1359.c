#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char item[2];
    int quantity;
    int lead_time;
} Shipment;

Shipment* generate_shipments(Shipment* data, int size) {
    Shipment* mutated_data = (Shipment*)malloc(size * sizeof(Shipment));
    for (int i = 0; i < size; i++) {
        mutated_data[i] = data[i];
        mutated_data[i].quantity = (int)(mutated_data[i].quantity * (0.8 + (float)rand() / RAND_MAX * 0.4));
        mutated_data[i].lead_time = (int)(mutated_data[i].lead_time * (0.9 + (float)rand() / RAND_MAX * 0.2));
    }
    return mutated_data;
}

Shipment* optimize_inventory(Shipment* data, int size) {
    Shipment* optimized_data = (Shipment*)malloc(size * sizeof(Shipment));
    for (int i = 0; i < size; i++) {
        optimized_data[i] = data[i];
        if (optimized_data[i].quantity > 100) {
            optimized_data[i].quantity = 100;
        }
        if (optimized_data[i].lead_time < 5) {
            optimized_data[i].lead_time = 5;
        }
    }
    return optimized_data;
}

void print_data(Shipment* data, int size) {
    for (int i = 0; i < size; i++) {
        printf("Item: %c, Quantity: %d, Lead Time: %d\n", data[i].item[0], data[i].quantity, data[i].lead_time);
    }
}

int main() {
    srand(time(NULL));
    Shipment initial_data[] = {{"A", 120, 4}, {"B", 90, 6}, {"C", 150, 3}};
    int size = sizeof(initial_data) / sizeof(initial_data[0]);
    Shipment* mutated_data = generate_shipments(initial_data, size);
    Shipment* optimized_data = optimize_inventory(mutated_data, size);
    print_data(optimized_data, size);
    free(mutated_data);
    free(optimized_data);
    return 0;
}