#include <stdio.h>
#include <stdlib.h>

double calculate_consensus(int* data, int length, double epsilon) {
    double total = 0;
    for (int i = 0; i < length; i++) {
        total += data[i];
    }
    double* weights = (double*)malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        weights[i] = data[i] / total;
    }
    double threshold = 0;
    for (int i = 0; i < length; i++) {
        threshold += weights[i];
    }
    threshold /= 2;
    for (int i = 0; i < length; i++) {
        double sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += weights[j];
        }
        if (sum >= threshold) {
            free(weights);
            return i;
        }
    }
    free(weights);
    return length - 1;
}

int main() {
    int data[] = {10, 20, 30, 40, 50};
    int length = sizeof(data) / sizeof(data[0]);
    double result = calculate_consensus(data, length, 1e-10);
    printf("%f\n", result);
    return 0;
}