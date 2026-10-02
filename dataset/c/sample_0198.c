#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name;
    int demand;
    int price;
    int cost;
} Item;

int optimize_supply_chain(Item *data, int length) {
    int cost = 0;
    for (int i = 0; i < length; i++) {
        cost += data[i].demand * data[i].price;
    }
    return cost;
}

Item* adjust_inventory(Item *data, int length, int budget) {
    for (int i = 0; i < length; i++) {
        if (data[i].cost > budget) {
            data[i].demand = 0;
        } else {
            data[i].demand = rand() % 10 + 1;
        }
    }
    return data;
}

void main() {
    Item supply_data[] = {{'A', 5, 20, 50}, {'B', 3, 30, 40}, {'C', 8, 10, 30}};
    int budget = 100;
    int length = sizeof(supply_data) / sizeof(supply_data[0]);
    Item *adjusted_data = adjust_inventory(supply_data, length, budget);
    int total_cost = optimize_supply_chain(adjusted_data, length);
    printf("%d\n", total_cost);
}