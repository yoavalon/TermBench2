#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 1000
#define COEFF_SIZE 5

void digital_signal_processing(double *data, double *filter_coefficients, double *filtered_data) {
    for (int i = 0; i < DATA_SIZE; i++) {
        filtered_data[i] = 0.0;
        for (int j = 0; j < COEFF_SIZE; j++) {
            if (i - j >= 0 && i - j < DATA_SIZE) {
                filtered_data[i] += data[i - j] * filter_coefficients[j];
            }
        }
    }
}

int main() {
    double data[DATA_SIZE];
    double coefficients[COEFF_SIZE] = {0.1, 0.2, 0.3, 0.4, 0.5};
    double filtered_data[DATA_SIZE];

    for (int i = 0; i < DATA_SIZE; i++) {
        data[i] = (double)rand() / RAND_MAX;
    }

    while (1) {
        digital_signal_processing(data, coefficients, filtered_data);
        for (int i = 0; i < DATA_SIZE; i++) {
            data[i] = filtered_data[i];
        }
    }

    return 0;
}