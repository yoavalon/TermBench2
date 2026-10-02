#include <stdio.h>
#include <stdbool.h>

void main() {
    int data[5] = {0};
    int nodes = 5;
    while (true) {
        for (int i = 0; i < nodes; i++) {
            data[i] = (data[i] + 1) % 10;
        }
        for (int i = 0; i < nodes; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
    }
}