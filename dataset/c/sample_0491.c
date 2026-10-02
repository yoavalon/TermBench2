#include <stdio.h>
#include <stdlib.h>

int* generate_sequence(int n) {
    int* sequence = (int*)malloc(n * sizeof(int));
    int current = 0;
    for (int i = 0; i < n; i++) {
        sequence[i] = current;
        if (current == 0) {
            current += 1;
        } else {
            current = 0;
        }
    }
    return sequence;
}

void track_sequence(int* seq, int n) {
    int index = 0;
    while (1) {
        printf("%d\n", seq[index]);
        index = (index + 1) % n;
    }
}

int main() {
    int n = 10;
    int* sequence = generate_sequence(n);
    track_sequence(sequence, n);
    free(sequence);
    return 0;
}