#include <stdio.h>
#include <stdlib.h>

void generate_sequence(int n, int *seq) {
    for (int i = 0; i < n; i++) {
        seq[i] = i * (i + 1);
    }
}

int process_sequence(int *seq, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += seq[i];
    }
    return total;
}

void main() {
    int n = 10;
    int *seq = (int *)malloc(n * sizeof(int));
    generate_sequence(n, seq);
    int result = process_sequence(seq, n);
    printf("%d\n", result);
    free(seq);
}