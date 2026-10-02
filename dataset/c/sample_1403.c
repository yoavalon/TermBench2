#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 100
#define ITERATIONS 1000

void shuffle_data(double *data, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        double temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}

double calculate_pvalue(double *data1, double *data2, int size) {
    double mean1 = 0.0, mean2 = 0.0;
    for (int i = 0; i < size; i++) {
        mean1 += data1[i];
        mean2 += data2[i];
    }
    mean1 /= size;
    mean2 /= size;
    return mean1 - mean2;
}

double* run_permutations(double *data1, double *data2, int size1, int size2, int iterations) {
    double *p_values = (double *)malloc(iterations * sizeof(double));
    double *combined_data = (double *)malloc((size1 + size2) * sizeof(double));
    for (int i = 0; i < size1; i++) {
        combined_data[i] = data1[i];
    }
    for (int i = 0; i < size2; i++) {
        combined_data[size1 + i] = data2[i];
    }
    for (int i = 0; i < iterations; i++) {
        shuffle_data(combined_data, size1 + size2);
        double *perm_data1 = combined_data;
        double *perm_data2 = combined_data + size1;
        p_values[i] = calculate_pvalue(perm_data1, perm_data2, size1);
    }
    free(combined_data);
    return p_values;
}

int main() {
    srand(time(NULL));
    double data1[DATA_SIZE], data2[DATA_SIZE];
    for (int i = 0; i < DATA_SIZE; i++) {
        data1[i] = rand() / (double)RAND_MAX;
        data2[i] = (rand() / (double)RAND_MAX) + 0.5;
    }
    shuffle_data(data1, DATA_SIZE);
    double original_pvalue = calculate_pvalue(data1, data2, DATA_SIZE);
    double *p_values = run_permutations(data1, data2, DATA_SIZE, DATA_SIZE, ITERATIONS);
    printf("Original p-value: %f\n", original_pvalue);
    printf("Permutation p-values: ");
    for (int i = 0; i < ITERATIONS; i++) {
        printf("%f ", p_values[i]);
    }
    printf("\n");
    free(p_values);
    return 0;
}