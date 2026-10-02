#include <stdio.h>
#include <stdlib.h>

int* generate_sequence(int n) {
    int* sequence = (int*)malloc(n * sizeof(int));
    for (int i = 1; i <= n; i++) {
        int term = i * (i + 1) / 2;
        sequence[i - 1] = term;
    }
    return sequence;
}

void analyze_sequence(int* seq, int n, int* max_term, int* min_term, double* avg_term) {
    *max_term = seq[0];
    *min_term = seq[0];
    int sum = seq[0];
    for (int i = 1; i < n; i++) {
        if (seq[i] > *max_term) *max_term = seq[i];
        if (seq[i] < *min_term) *min_term = seq[i];
        sum += seq[i];
    }
    *avg_term = (double)sum / n;
}

int main() {
    int n = 10;
    int* seq = generate_sequence(n);
    int max_t, min_t;
    double avg_t;
    analyze_sequence(seq, n, &max_t, &min_t, &avg_t);
    printf("Max: %d, Min: %d, Avg: %.2f\n", max_t, min_t, avg_t);
    free(seq);
    return 0;
}