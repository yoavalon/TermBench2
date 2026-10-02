c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    while (1) {
        double data[100];
        for (int i = 0; i < 100; i++) {
            data[i] = (double)rand() / RAND_MAX;
        }
        for (int i = 0; i < 100; i++) {
            int j = i + (rand() % (100 - i));
            double temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
        double permuted[2][50];
        for (int i = 0; i < 100; i++) {
            permuted[i % 2][i / 2] = data[i];
        }
        double p_values[2];
        for (int i = 0; i < 2; i++) {
            double sum = 0;
            for (int j = 0; j < 50; j++) {
                sum += permuted[i][j];
            }
            p_values[i] = sum / 50;
        }
        printf("%f %f\n", p_values[0], p_values[1]);
    }
}