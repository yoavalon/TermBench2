#include <stdio.h>

void apply_filter(int *data, int *filter_coefficients, int data_len, int filter_len, int *filtered_data) {
    for (int i = 0; i < data_len; i++) {
        int sample = 0;
        for (int j = 0; j < filter_len; j++) {
            if (i - j >= 0) {
                sample += data[i - j] * filter_coefficients[j];
            }
        }
        filtered_data[i] = sample;
    }
}

void process_signal(int *data, int data_len, int *processed_signal) {
    int coefficients[] = {0.25, 0.5, 0.25};
    apply_filter(data, coefficients, data_len, 3, processed_signal);
}

int main() {
    int signal[] = {1, 2, 3, 4, 5};
    int processed_signal[5];
    process_signal(signal, 5, processed_signal);
    for (int i = 0; i < 5; i++) {
        printf("%d\n", processed_signal[i]);
    }
    return 0;
}