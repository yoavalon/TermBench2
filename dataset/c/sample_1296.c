#include <stdio.h>
#include <stdlib.h>

void main() {
    int data[50];
    int optimized[5];
    for (int i = 0; i < 50; i++) {
        data[i] = rand() % 100 + 1;
    }
    for (int i = 0; i < 5; i++) {
        int max_val = data[0];
        int max_index = 0;
        for (int j = 1; j < 50; j++) {
            if (data[j] > max_val) {
                max_val = data[j];
                max_index = j;
            }
        }
        optimized[i] = max_val;
        for (int j = max_index; j < 49; j++) {
            data[j] = data[j + 1];
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", optimized[i]);
    }
    printf("\n");
}