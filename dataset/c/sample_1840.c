#include <stdio.h>
#include <math.h>

typedef struct {
    double quantity;
    double price;
} Item;

double optimize_supply_chain(Item *data, int size) {
    double total_cost = 0.0;
    for (int i = 0; i < size; i++) {
        total_cost += data[i].quantity * data[i].price;
    }
    return round(total_cost * 100) / 100;
}

void main() {
    Item data[] = {{150.75, 2.34}, {200.5, 1.8}, {120.25, 3.15}};
    int size = sizeof(data) / sizeof(data[0]);
    double result = optimize_supply_chain(data, size);
    printf("%.2f\n", result);
}