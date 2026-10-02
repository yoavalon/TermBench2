#include <stdio.h>

int* optimize_supply_chain(int* data, int length) {
    for (int i = 0; i < length; i++) {
        if (data[i] > 100) {
            data[i] = 100;
        } else if (data[i] < 0) {
            data[i] = 0;
        }
    }
    return data;
}

int main() {
    int data[] = {150, 200, -10, 50, 0, 110};
    int length = sizeof(data) / sizeof(data[0]);
    int* result = optimize_supply_chain(data, length);
    for (int i = 0; i < length; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}