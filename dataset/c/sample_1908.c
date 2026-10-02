#include <stdio.h>

void process_signal(double data[], int length, double processed_data[]) {
    for (int i = 0; i < length; i++) {
        processed_data[i] = data[i] * 0.5 + 0.3;
    }
}

void filter_signal(double data[], int length, double threshold, double result[], int *result_length) {
    *result_length = 0;
    for (int i = 0; i < length; i++) {
        if (data[i] > threshold) {
            result[*result_length] = data[i];
            (*result_length)++;
        }
    }
}

int main() {
    double data[] = {1.2, 2.3, 3.4, 4.5, 5.6};
    int data_length = sizeof(data) / sizeof(data[0]);
    double processed[data_length];
    double result[data_length];
    int result_length;

    process_signal(data, data_length, processed);
    filter_signal(processed, data_length, 2.0, result, &result_length);

    for (int i = 0; i < result_length; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");

    return 0;
}