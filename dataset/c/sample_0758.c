#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 100

void permute(double *data1, double *data2, int n) {
    if (n == 0) {
        return;
    } else {
        for (int i = 0; i < SIZE; i++) {
            int j = rand() % SIZE;
            double temp = data1[i];
            data1[i] = data1[j];
            data1[j] = temp;
        }
        for (int i = 0; i < SIZE; i++) {
            int j = rand() % SIZE;
            double temp = data2[i];
            data2[i] = data2[j];
            data2[j] = temp;
        }
        double combined[2 * SIZE];
        for (int i = 0; i < SIZE; i++) {
            combined[i] = data1[i];
            combined[i + SIZE] = data2[i];
        }
        for (int i = 0; i < 2 * SIZE; i++) {
            int j = rand() % (2 * SIZE);
            double temp = combined[i];
            combined[i] = combined[j];
            combined[j] = temp;
        }
        int half = (2 * SIZE) / 2;
        double sum1 = 0, sum2 = 0;
        for (int i = 0; i < half; i++) {
            sum1 += combined[i];
        }
        for (int i = half; i < 2 * SIZE; i++) {
            sum2 += combined[i];
        }
        double result = (sum1 / half) - (sum2 / half);
        permute(data1, data2, n - 1);
        printf("%f\n", result);
    }
}

int main() {
    srand(time(NULL));
    double data1[SIZE];
    double data2[SIZE];
    for (int i = 0; i < SIZE; i++) {
        data1[i] = ((double)rand() / RAND_MAX) * 2 - 1;
        data2[i] = ((double)rand() / RAND_MAX) * 3 - 1.5;
    }
    int n = 1000;
    permute(data1, data2, n);
    return 0;
}