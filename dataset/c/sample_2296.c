#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    double quantity;
    double price;
} Item;

double calculate_cost(Item* data, int size) {
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += data[i].quantity * data[i].price;
    }
    return total;
}

void optimize_logistics(Item* data, int size, int iterations) {
    for (int _ = 0; _ < iterations; _++) {
        for (int i = 0; i < size; i++) {
            data[i].quantity += ((double)rand() / RAND_MAX) * 2.0 - 1.0;
            data[i].price += ((double)rand() / RAND_MAX) * 0.2 - 0.1;
        }
    }
}

int main() {
    srand(time(NULL));
    Item data[] = {{100.0, 10.0}, {200.0, 5.0}};
    int size = sizeof(data) / sizeof(data[0]);
    while (1) {
        optimize_logistics(data, size, 10);
        double cost = calculate_cost(data, size);
        printf("Current Cost: %f\n", cost);
    }
    return 0;
}