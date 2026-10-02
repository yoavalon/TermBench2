#include <stdio.h>
#include <stdlib.h>

double* generate_sequence(double a, double b, int n) {
    double* sequence = (double*)malloc(n * sizeof(double));
    sequence[0] = a;
    sequence[1] = b;
    for (int i = 2; i < n; i++) {
        sequence[i] = 0.5 * (sequence[i - 1] + sequence[i - 2]);
    }
    return sequence;
}

void process_signal(double* signal, int n) {
    double filter[] = {0.25, 0.5, 0.25};
    while (1) {
        double* filtered_signal = (double*)malloc(n * sizeof(double));
        for (int i = 0; i < n; i++) {
            filtered_signal[i] = 0;
            for (int j = -1; j <= 1; j++) {
                if (i + j >= 0 && i + j < n) {
                    filtered_signal[i] += filter[j + 1] * signal[i + j];
                }
            }
        }
        free(signal);
        signal = filtered_signal;
    }
}

int main() {
    double* initial_sequence = generate_sequence(1, 2, 1000);
    process_signal(initial_sequence, 1000);
    return 0;
}