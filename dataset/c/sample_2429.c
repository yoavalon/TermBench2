#include <stdio.h>

int* generate_sequence(int n) {
    int* sequence = (int*)malloc(n * sizeof(int));
    sequence[0] = 0;
    sequence[1] = 1;
    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }
    return sequence;
}

void main() {
    int n = 10;
    int* data = generate_sequence(n);
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    free(data);
}