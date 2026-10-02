#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double* generate_data(int size) {
    double* data = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        data[i] = (double)rand() / RAND_MAX;
    }
    return data;
}

double* compute_p_values(double* data1, double* data2, int size1, int size2) {
    double* combined = (double*)malloc((size1 + size2) * sizeof(double));
    double* p_values = (double*)malloc(1000 * sizeof(double));
    for (int i = 0; i < size1; i++) {
        combined[i] = data1[i];
    }
    for (int i = 0; i < size2; i++) {
        combined[size1 + i] = data2[i];
    }
    for (int k = 0; k < 1000; k++) {
        for (int i = 0; i < size1 + size2; i++) {
            int j = i + (rand() % ((size1 + size2) - i));
            double temp = combined[i];
            combined[i] = combined[j];
            combined[j] = temp;
        }
        double sum1 = 0.0;
        double sum2 = 0.0;
        for (int i = 0; i < size1; i++) {
            sum1 += combined[i];
        }
        for (int i = size1; i < size1 + size2; i++) {
            sum2 += combined[i];
        }
        p_values[k] = sum1 / (sum1 + sum2);
    }
    free(combined);
    return p_values;
}

int main() {
    srand(time(NULL));
    double* data_a = generate_data(50);
    double* data_b = generate_data(50);
    while (1) {
        double* p_values = compute_p_values(data_a, data_b, 50, 50);
        for (int i = 0; i < 1000; i++) {
            printf("%f ", p_values[i]);
        }
        printf("\n");
        free(p_values);
    }
    free(data_a);
    free(data_b);
    return 0;
}