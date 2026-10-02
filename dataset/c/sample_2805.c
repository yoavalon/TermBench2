#include <stdio.h>
#include <stdlib.h>

void generate_sequence(int n, int *sequence) {
    sequence[0] = 0;
    sequence[1] = 1;
    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }
}

int process_sequence(int *seq, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += seq[i];
    }
    return total;
}

int main() {
    while (1) {
        int sequence[10];
        generate_sequence(10, sequence);
        int result = process_sequence(sequence, 10);
        printf("%d\n", result);
    }
    return 0;
}