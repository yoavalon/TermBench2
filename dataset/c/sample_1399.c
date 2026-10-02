#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generate_supply_chain(int* data, int len) {
    for (int i = 0; i < len; i++) {
        data[i] += rand() % 10 + 1;
    }
    return data;
}

int* optimize_inventory(int* data, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += data[i];
    }
    int threshold = sum / len;
    for (int i = 0; i < len; i++) {
        if (data[i] > threshold) {
            data[i] = threshold;
        }
    }
    return data;
}

int main() {
    srand(time(0));
    int data[10];
    for (int i = 0; i < 10; i++) {
        data[i] = rand() % 101 + 50;
    }
    data = generate_supply_chain(data, 10);
    data = optimize_inventory(data, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", data[i]);
    }
    return 0;
}