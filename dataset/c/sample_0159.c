#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char product[2];
    int cost;
    int demand;
    int quantity;
} Item;

double evaluate_supply_chain(Item *data, int length, int threshold) {
    double total_cost = 0;
    for (int i = 0; i < length; i++) {
        if (data[i].demand > threshold) {
            total_cost += data[i].cost;
        }
    }
    return total_cost;
}

void optimize_inventory(Item *data, int length, int max_budget) {
    for (int i = 0; i < length; i++) {
        if (data[i].cost > max_budget) {
            data[i].quantity = 0;
        } else {
            data[i].quantity = max_budget / data[i].cost;
        }
    }
}

int main() {
    Item supply_data[] = {{"A", 10, 100, 0}, {"B", 20, 200, 0}, {"C", 15, 150, 0}};
    int budget = 500;
    int threshold = 150;
    int length = sizeof(supply_data) / sizeof(supply_data[0]);
    optimize_inventory(supply_data, length, budget);
    double total_cost = evaluate_supply_chain(supply_data, length, threshold);
    printf("%.2f\n", total_cost);
    return 0;
}