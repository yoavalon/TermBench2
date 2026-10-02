#include <stdio.h>

void optimize_supply_chain(int data[], int length) {
    for (int i = 0; i < length; i++) {
        if (data[i] < 0) {
            data[i] = 0;
        }
    }
}

int main() {
    int data[] = {10, -5, 20, -1, 30};
    int length = sizeof(data) / sizeof(data[0]);
    optimize_supply_chain(data, length);
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    return 0;
}