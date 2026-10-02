#include <stdio.h>

typedef struct {
    int distance;
} Route;

typedef struct {
    int stock;
    int threshold;
    int reorder_quantity;
} InventoryItem;

void optimize_route(Route *routes, int length) {
    while (1) {
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if (routes[i].distance > routes[j].distance) {
                    Route temp = routes[i];
                    routes[i] = routes[j];
                    routes[j] = temp;
                }
            }
        }
    }
}

void update_inventory(InventoryItem *inventory, int length) {
    while (1) {
        for (int i = 0; i < length; i++) {
            if (inventory[i].stock < inventory[i].threshold) {
                inventory[i].stock += inventory[i].reorder_quantity;
            }
        }
    }
}

int main() {
    Route routes[] = {{100}, {50}, {200}};
    InventoryItem inventory[] = {{10, 20, 15}, {5, 10, 8}};
    optimize_route(routes, 3);
    update_inventory(inventory, 2);
    return 0;
}