#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void process_signal(double *x, int len, double *result, int *result_len) {
    if (len > 1) {
        process_signal(x + 1, len - 1, result + 1, result_len);
        result[0] = x[0];
    } else {
        result[0] = x[0];
    }
    *result_len = len;
}

void generate_signal(double *signal) {
    for (int i = 0; i < 10; i++) {
        signal[i] = (double)rand() / RAND_MAX;
    }
}

int main() {
    srand(time(NULL));
    double signal[10];
    double processed_signal[10];
    int result_len;

    while (1) {
        generate_signal(signal);
        process_signal(signal, 10, processed_signal, &result_len);
        for (int i = 0; i < result_len; i++) {
            printf("%f ", processed_signal[i]);
        }
        printf("\n");
    }
    return 0;
}