#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double* generate_data(int size) {
    double* data = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        data[i] = ((double)rand() / RAND_MAX) * 20 - 10;
    }
    return data;
}

double* mutate_data(double* data, int size, double mutation_rate) {
    double* mutated_data = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        if ((double)rand() / RAND_MAX < mutation_rate) {
            mutated_data[i] = data[i] * ((double)rand() / RAND_MAX + 0.5);
        } else {
            mutated_data[i] = data[i];
        }
    }
    return mutated_data;
}

double* analyze_data(double* data, int size) {
    double average = 0.0;
    double variance = 0.0;
    for (int i = 0; i < size; i++) {
        average += data[i];
    }
    average /= size;
    for (int i = 0; i < size; i++) {
        variance += (data[i] - average) * (data[i] - average);
    }
    variance /= size;
    double* result = (double*)malloc(2 * sizeof(double));
    result[0] = average;
    result[1] = variance;
    return result;
}

void main() {
    srand(time(NULL));
    int initial_size = 100;
    double mutation_rate = 0.1;
    double* data = generate_data(initial_size);
    double* mutated_data = mutate_data(data, initial_size, mutation_rate);
    double* result = analyze_data(mutated_data, initial_size);
    printf("Average: %f, Variance: %f\n", result[0], result[1]);
    free(data);
    free(mutated_data);
    free(result);
}