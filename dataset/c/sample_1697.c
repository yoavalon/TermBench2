#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generate_data() {
    static int data[10];
    for (int i = 0; i < 10; i++) {
        data[i] = rand() % 100 + 1;
    }
    return data;
}

int* process_data(int* data) {
    static int processed[10];
    for (int i = 0; i < 10; i++) {
        if (data[i] % 2 == 0) {
            processed[i] = data[i] * 2;
        } else {
            processed[i] = data[i] - 1;
        }
    }
    return processed;
}

void main() {
    srand(time(NULL));
    while (1) {
        int* data = generate_data();
        int* processed_data = process_data(data);
        for (int i = 0; i < 10; i++) {
            printf("%d ", processed_data[i]);
        }
        printf("\n");
    }
}