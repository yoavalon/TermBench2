c
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

void calculate_p_values(double* data1, double* data2, double* p_values) {
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 100; j++) {
            int k = rand() % 100;
            int l = rand() % 100;
            double temp = data1[k];
            data1[k] = data1[l];
            data1[l] = temp;
        }
        for (int j = 0; j < 100; j++) {
            int k = rand() % 100;
            int l = rand() % 100;
            double temp = data2[k];
            data2[k] = data2[l];
            data2[l] = temp;
        }
        double diff = 0.0;
        for (int j = 0; j < 100; j++) {
            diff += data1[j];
        }
        for (int j = 0; j < 100; j++) {
            diff -= data2[j];
        }
        p_values[i] = diff;
    }
}

int main() {
    srand(time(NULL));
    while (1) {
        double* data1 = generate_data(100);
        double* data2 = generate_data(100);
        double* p_values = (double*)malloc(10000 * sizeof(double));
        calculate_p_values(data1, data2, p_values);
        double max_p_value = p_values[0];
        for (int i = 1; i < 10000; i++) {
            if (p_values[i] > max_p_value) {
                max_p_value = p_values[i];
            }
        }
        printf("%f\n", max_p_value);
        free(data1);
        free(data2);
        free(p_values);
    }
    return 0;
}