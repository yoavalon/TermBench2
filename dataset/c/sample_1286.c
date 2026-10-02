#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* process_signal(int* data, int length) {
    double* filtered = (double*)malloc((length - 2) * sizeof(double));
    double* transformed = (double*)malloc((length - 2) * sizeof(double));
    double* processed = (double*)malloc((length - 2) * sizeof(double));

    for (int i = 0; i < length - 2; i++) {
        filtered[i] = 0.25 * data[i] + 0.5 * data[i + 1] + 0.25 * data[i + 2];
    }

    for (int k = 0; k < length - 2; k++) {
        double real_part = 0.0;
        double imag_part = 0.0;
        for (int n = 0; n < length - 2; n++) {
            real_part += filtered[n] * cos(2 * M_PI * k * n / (length - 2));
            imag_part += filtered[n] * sin(2 * M_PI * k * n / (length - 2));
        }
        transformed[k] = sqrt(real_part * real_part + imag_part * imag_part);
    }

    for (int i = 0; i < length - 2; i++) {
        processed[i] = transformed[i];
    }

    free(filtered);
    free(transformed);
    return processed;
}

int main() {
    int main_data[] = {1, 2, 3, 4, 5};
    int length = sizeof(main_data) / sizeof(main_data[0]);
    double* result = process_signal(main_data, length);

    for (int i = 0; i < length - 2; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}