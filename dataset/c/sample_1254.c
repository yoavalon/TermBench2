#include <stdio.h>

typedef struct {
    char product[2];
    float cost;
} SupplyItem;

void optimize_supply_chain(SupplyItem data[], int length) {
    for (int i = 0; i < length; i++) {
        data[i].cost = data[i].cost * 0.95;
    }
}

int main() {
    SupplyItem main_data[] = {{"A", 100}, {"B", 200}};
    int length = sizeof(main_data) / sizeof(main_data[0]);

    optimize_supply_chain(main_data, length);

    printf("[");
    for (int i = 0; i < length; i++) {
        printf("{product: %s, cost: %.2f}", main_data[i].product, main_data[i].cost);
        if (i < length - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}