#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* generate_sequence(int n, double a0, double r) {
    double* seq = (double*)malloc(n * sizeof(double));
    seq[0] = a0;
    for (int i = 1; i < n; i++) {
        double next_value = seq[i - 1] * r;
        seq[i] = next_value;
    }
    return seq;
}

double* filter_sequence(double* seq, int len, double threshold) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (fabs(seq[i]) > threshold) {
            count++;
        }
    }
    double* filtered = (double*)malloc(count * sizeof(double));
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (fabs(seq[i]) > threshold) {
            filtered[index++] = seq[i];
        }
    }
    free(seq);
    return filtered;
}

double* analyze_signal(double* seq, int len, int window_size) {
    int count = len - window_size + 1;
    double* analysis = (double*)malloc(count * sizeof(double));
    for (int i = 0; i < count; i++) {
        double sum = 0;
        for (int j = 0; j < window_size; j++) {
            sum += seq[i + j];
        }
        analysis[i] = sum / window_size;
    }
    free(seq);
    return analysis;
}

void main() {
    int n = 10;
    double a0 = 1;
    double r = 2;
    double threshold = 10;
    int window_size = 3;
    double* sequence = generate_sequence(n, a0, r);
    double* filtered_sequence = filter_sequence(sequence, n, threshold);
    double* signal_analysis = analyze_signal(filtered_sequence, n - 1, window_size);
    for (int i = 0; i < n; i++) {
        printf("%f ", sequence[i]);
    }
    printf("\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%f ", filtered_sequence[i]);
    }
    printf("\n");
    for (int i = 0; i < n - window_size + 1; i++) {
        printf("%f ", signal_analysis[i]);
    }
    printf("\n");
}