#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* update_inventory(int* stock, int* orders, int num_items) {
    for (int i = 0; i < num_items; i++) {
        stock[i] += orders[i];
    }
    return stock;
}

int* generate_orders(int num_items, int max_order) {
    int* orders = (int*)malloc(num_items * sizeof(int));
    for (int i = 0; i < num_items; i++) {
        orders[i] = rand() % (max_order + 1);
    }
    return orders;
}

int main() {
    int stock[] = {100, 150, 200, 250, 300};
    int num_items = sizeof(stock) / sizeof(stock[0]);
    int max_order = 50;
    srand(time(0));
    while (1) {
        int* orders = generate_orders(num_items, max_order);
        update_inventory(stock, orders, num_items);
        for (int i = 0; i < num_items; i++) {
            printf("%d ", stock[i]);
        }
        printf("\n");
        free(orders);
    }
    return 0;
}