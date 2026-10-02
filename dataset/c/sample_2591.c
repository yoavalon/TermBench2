#include <stdio.h>

int* generate_sequence(int n, int a, int b) {
    static int sequence[1000];
    sequence[0] = a;
    sequence[1] = b;
    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }
    return sequence;
}

void analyze_sequence(int* seq, int n, int* max_value, double* avg_value) {
    *max_value = seq[0];
    double sum = 0;
    for (int i = 0; i < n; i++) {
        if (seq[i] > *max_value) {
            *max_value = seq[i];
        }
        sum += seq[i];
    }
    *avg_value = sum / n;
}

int main() {
    int n = 10;
    int* seq = generate_sequence(n, 0, 1);
    int max_val;
    double avg_val;
    analyze_sequence(seq, n, &max_val, &avg_val);
    printf("Max Value: %d, Average Value: %.2f\n", max_val, avg_val);
    return 0;
}