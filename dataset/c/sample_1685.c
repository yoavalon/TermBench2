#include <stdio.h>
#include <stdlib.h>

int* generate_sequence(int start, int increment, int length) {
    int* sequence = (int*)malloc(length * sizeof(int));
    sequence[0] = start;
    for (int i = 1; i < length; i++) {
        sequence[i] = sequence[i - 1] + increment;
    }
    return sequence;
}

int* update_sequence(int* sequence, int modifier, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] += modifier;
    }
    return sequence;
}

void print_sequence(int* sequence, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");
}

int main() {
    int* seq = generate_sequence(0, 1, 10);
    while (1) {
        seq = update_sequence(seq, 2, 10);
        print_sequence(seq, 10);
    }
    free(seq);
    return 0;
}