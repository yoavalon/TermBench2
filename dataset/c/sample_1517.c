c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simulate() {
    double data[10];
    for (int i = 0; i < 10; i++) {
        data[i] = (double)rand() / RAND_MAX;
    }
    while (1) {
        for (int i = 0; i < 10; i++) {
            data[i] += 0.01;
        }
        for (int i = 0; i < 10; i++) {
            printf("%f ", data[i]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    simulate();
    return 0;
}