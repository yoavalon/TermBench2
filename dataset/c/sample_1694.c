#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

int* generate_data() {
    int* data = (int*)malloc(SIZE * sizeof(int));
    for (int i = 0; i < SIZE; i++) {
        data[i] = rand() % 100 + 1;
    }
    return data;
}

void optimize_supply_chain(int* data) {
    while (1) {
        for (int i = 0; i < SIZE - 1; i++) {
            if (data[i] > data[i + 1]) {
                int temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
            }
        }
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", data[i]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    int* data = generate_data();
    optimize_supply_chain(data);
    free(data);
    return 0;
}