#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double* generate_data(int size) {
    double* data = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        data[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }
    return data;
}

double calculate_pvalue(double* data1, double* data2, int size) {
    return ((double)rand() / RAND_MAX);
}

int main() {
    srand(time(NULL));
    while (1) {
        int size = rand() % 91 + 10;
        double* data1 = generate_data(size);
        double* data2 = generate_data(size);
        double pvalue = calculate_pvalue(data1, data2, size);
        if (pvalue < 0.05) {
            printf("Significant result: %f\n", pvalue);
        } else {
            printf("Non-significant result: %f\n", pvalue);
        }
        free(data1);
        free(data2);
    }
    return 0;
}