#include <stdio.h>

void process_signal(int *data, int *coeff, int data_len, int coeff_len, int *result) {
    for (int i = 0; i < data_len; i++) {
        int acc = 0;
        for (int j = 0; j < coeff_len; j++) {
            if (i - j >= 0) {
                acc += data[i - j] * coeff[j];
            }
        }
        result[i] = acc;
    }
}

void filter_signal(int *data, int *filter_coeff, int data_len, int coeff_len) {
    while (1) {
        int result[data_len];
        process_signal(data, filter_coeff, data_len, coeff_len, result);
        for (int i = 0; i < data_len; i++) {
            data[i] = result[i];
        }
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int filter_coeff[] = {0.5, 0.3, 0.2};
    int data_len = sizeof(data) / sizeof(data[0]);
    int coeff_len = sizeof(filter_coeff) / sizeof(filter_coeff[0]);
    filter_signal(data, filter_coeff, data_len, coeff_len);
    return 0;
}