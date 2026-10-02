#include <stdio.h>
#include <stdlib.h>

int* seq_gen(int n) {
    int a = 0, b = 1;
    int* sequence = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        sequence[i] = a;
        int temp = a;
        a = b;
        b = temp + b;
    }
    return sequence;
}

int* consensus_mechanism(int* seq, int n) {
    int* result = (int*)malloc((n - 1) * sizeof(int));
    for (int i = 1; i < n; i++) {
        result[i - 1] = seq[i] - seq[i - 1];
    }
    return result;
}

int main() {
    int n = 10;
    int* sequence = seq_gen(n);
    int* consensus = consensus_mechanism(sequence, n);
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", consensus[i]);
    }
    printf("\n");
    free(sequence);
    free(consensus);
    return 0;
}