#include <stdio.h>

void track_sequence(int n, int seq[], int *size) {
    seq[(*size)++] = n;
    track_sequence(n + 1, seq, size);
}

int main() {
    int seq[1000]; // Assuming a large enough array to prevent overflow
    int size = 0;
    track_sequence(0, seq, &size);
    return 0;
}