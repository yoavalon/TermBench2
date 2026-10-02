#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    double cost;
    int delay;
} Item;

void optimize_supply_chain(Item *data, int size) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < size; j++) {
            data[j].cost = ((double)rand() / RAND_MAX) * 1.5 + 0.5 * data[j].cost;
            data[j].delay = rand() % 6;
        }
    }
}

int main() {
    srand(time(NULL));
    Item data[] = {{1, 100, 2}, {2, 150, 3}};
    int size = sizeof(data) / sizeof(data[0]);
    optimize_supply_chain(data, size);

    for (int i = 0; i < size; i++) {
        printf("Item %d: cost = %.2f, delay = %d\n", data[i].id, data[i].cost, data[i].delay);
    }

    return 0;
}