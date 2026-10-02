#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DATA_SIZE 100
#define ITERATIONS 1000

double calculate_p_value(double data1[], double data2[], int iterations) {
    double observed_diff = 0.0;
    for (int i = 0; i < DATA_SIZE; i++) {
        observed_diff += data1[i];
    }
    observed_diff /= DATA_SIZE;
    for (int i = 0; i < DATA_SIZE; i++) {
        observed_diff -= data2[i];
    }
    observed_diff /= DATA_SIZE;

    double combined[2 * DATA_SIZE];
    for (int i = 0; i < DATA_SIZE; i++) {
        combined[i] = data1[i];
        combined[i + DATA_SIZE] = data2[i];
    }

    int count = 0;
    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < 2 * DATA_SIZE - 1; i++) {
            int j = i + (rand() % (2 * DATA_SIZE - i));
            double temp = combined[i];
            combined[i] = combined[j];
            combined[j] = temp;
        }
        double new_diff = 0.0;
        for (int i = 0; i < DATA_SIZE; i++) {
            new_diff += combined[i];
        }
        new_diff /= DATA_SIZE;
        for (int i = DATA_SIZE; i < 2 * DATA_SIZE; i++) {
            new_diff -= combined[i];
        }
        new_diff /= DATA_SIZE;
        if (new_diff >= observed_diff) {
            count++;
        }
    }
    return (double)count / iterations;
}

int main() {
    double data1[DATA_SIZE];
    double data2[DATA_SIZE];
    for (int i = 0; i < DATA_SIZE; i++) {
        data1[i] = 0.0 + (1.0 - 0.0) * ((double)rand() / RAND_MAX);
        data2[i] = 0.5 + (1.0 - 0.0) * ((double)rand() / RAND_MAX);
    }
    double p_value = calculate_p_value(data1, data2, ITERATIONS);
    printf("P-value: %f\n", p_value);
    return 0;
}