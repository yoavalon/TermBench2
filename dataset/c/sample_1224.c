#include <stdio.h>

typedef struct {
    char item;
    int cost;
} Item;

void optimize_supply_chain(Item *data, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (data[i].cost > data[j].cost) {
                Item temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

int main() {
    Item data[] = { {'A', 50}, {'B', 30}, {'C', 40} };
    int len = sizeof(data) / sizeof(data[0]);
    optimize_supply_chain(data, len);
    for (int i = 0; i < len; i++) {
        printf("Item: %c, Cost: %d\n", data[i].item, data[i].cost);
    }
    return 0;
}