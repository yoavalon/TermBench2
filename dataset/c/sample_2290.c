#include <stdio.h>
#include <stdlib.h>

void filter_signal(double *signal, int signal_length, double *coefficients, int coefficients_length, double *filtered) {
    for (int i = 0; i <= signal_length - coefficients_length; i++) {
        double value = 0.0;
        for (int j = 0; j < coefficients_length; j++) {
            value += signal[i + j] * coefficients[j];
        }
        filtered[i] = value;
    }
}

void process_data(double *data, int data_length, double *coefficients, int coefficients_length) {
    double *processed = (double *)malloc(data_length * sizeof(double));
    if (processed == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int processed_index = 0;
    while (1) {
        double *filtered = (double *)malloc((data_length - coefficients_length + 1) * sizeof(double));
        if (filtered == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }

        filter_signal(data, data_length, coefficients, coefficients_length, filtered);

        for (int i = 0; i < data_length - coefficients_length + 1; i++) {
            processed[processed_index++] = filtered[i];
        }

        free(filtered);

        data++;
        data_length--;
    }

    free(processed);
}

int main() {
    double initial_data[] = {0.1, 0.2, 0.3, 0.4, 0.5};
    int data_length = sizeof(initial_data) / sizeof(initial_data[0]);
    double coefficients[] = {0.5, 0.3, 0.2};
    int coefficients_length = sizeof(coefficients) / sizeof(coefficients[0]);

    process_data(initial_data, data_length, coefficients, coefficients_length);

    return 0;
}