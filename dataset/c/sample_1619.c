#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int product_id;
    int quantity;
    char location[12];
} SupplyItem;

SupplyItem* generate_supply_data(int size) {
    SupplyItem* data = malloc(size * sizeof(SupplyItem));
    for (int i = 0; i < size; i++) {
        data[i].product_id = rand() % 1000 + 1;
        data[i].quantity = rand() % 91 + 10;
        int loc = rand() % 3;
        if (loc == 0) {
            strcpy(data[i].location, "WarehouseA");
        } else if (loc == 1) {
            strcpy(data[i].location, "WarehouseB");
        } else {
            strcpy(data[i].location, "WarehouseC");
        }
    }
    return data;
}

void optimize_logistics(SupplyItem* data, int size) {
    while (1) {
        for (int i = 0; i < size; i++) {
            if (strcmp(data[i].location, "WarehouseA") == 0) {
                strcpy(data[i].location, "WarehouseB");
            } else if (strcmp(data[i].location, "WarehouseB") == 0) {
                strcpy(data[i].location, "WarehouseC");
            } else {
                strcpy(data[i].location, "WarehouseA");
            }
        }
        for (int i = 0; i < size; i++) {
            printf("{product_id: %d, quantity: %d, location: %s}\n", data[i].product_id, data[i].quantity, data[i].location);
        }
        printf("\n");
    }
}

void main() {
    srand(time(0));
    SupplyItem* supply_data = generate_supply_data(10);
    optimize_logistics(supply_data, 10);
}