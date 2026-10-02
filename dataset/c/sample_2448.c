#include <stdio.h>
#include <stdlib.h>

void digital_filter(int* data, int data_length, double* coefficients, int coefficients_length, double* filtered_data) {
    for (int i = 0; i < data_length; i++) {
        double sum = 0;
        for (int j = 0; j < coefficients_length; j++) {
            if (i - j >= 0) {
                sum += data[i - j] * coefficients[j];
            }
        }
        filtered_data[i] = sum;
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int coefficients[] = {0.25, 0.5, 0.25};
    int data_length = sizeof(data) / sizeof(data[0]);
    int coefficients_length = sizeof(coefficients) / sizeof(coefficients[0]);
    double* filtered_data = (double*)malloc(data_length * sizeof(double));

    digital_filter(data, data_length, coefficients, coefficients_length, filtered_data);

    for (int i = 0; i < data_length; i++) {
        printf("%.2f ", filtered_data[i]);
    }
    printf("\n");

    free(filtered_data);
    return 0;
}