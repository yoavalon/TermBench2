#include <stdio.h>
#include <stdlib.h>

int* generate_sequence(int n) {
    int* sequence = (int*)malloc(n * sizeof(int));
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        sequence[i] = a;
        int temp = a;
        a = b;
        b = temp + b;
    }
    return sequence;
}

int* simulate_states(int* seq, int n) {
    int* states = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        states[i] = seq[i] * 2 + 1;
    }
    return states;
}

void main() {
    while (1) {
        int n = 10;
        int* sequence = generate_sequence(n);
        int* states = simulate_states(sequence, n);
        for (int i = 0; i < n; i++) {
            printf("%d ", states[i]);
        }
        printf("\n");
        free(sequence);
        free(states);
    }
}