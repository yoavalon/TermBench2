#include <stdio.h>

double apply_boundary_conditions(double signal[], int length, const char* condition_type) {
    double result[length];
    for (int i = 0; i < length; i++) {
        if (strcmp(condition_type, "zero") == 0) {
            result[i] = (signal[i] < 0) ? 0 : signal[i];
        } else if (strcmp(condition_type, "clip") == 0) {
            result[i] = (signal[i] > 1) ? 1 : (signal[i] < 0) ? 0 : signal[i];
        } else {
            result[i] = signal[i];
        }
    }
    return result;
}

double* process_signal(double signal[], int length, const char* condition) {
    double processed_signal[length];
    for (int i = 0; i < length; i++) {
        processed_signal[i] = apply_boundary_conditions(signal, length, condition)[i] * 0.5;
    }
    return processed_signal;
}

int main() {
    double data[] = {0.1, -0.3, 0.8, 1.2, -0.5, 0.9};
    int length = sizeof(data) / sizeof(data[0]);
    double* result = process_signal(data, length, "clip");
    for (int i = 0; i < length; i++) {
        printf("%f ", result[i]);
    }
    return 0;
}