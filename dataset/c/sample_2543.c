#include <stdio.h>
#include <stdlib.h>

int* generate_sequence(int n) {
    int* sequence = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        sequence[i] = i * (i + 1) / 2;
    }
    return sequence;
}

void analyze_sequence(int* seq, int n) {
    int* result = (int*)calloc(55, sizeof(int)); // Assuming max value is 45 (for n=10)
    for (int i = 0; i < n; i++) {
        result[seq[i]] = i;
    }
    for (int i = 0; i < 55; i++) {
        if (result[i] != 0) {
            printf("%d: %d\n", i, result[i]);
        }
    }
    free(result);
}

int main() {
    int n = 10;
    int* seq = generate_sequence(n);
    analyze_sequence(seq, n);
    free(seq);
    return 0;
}