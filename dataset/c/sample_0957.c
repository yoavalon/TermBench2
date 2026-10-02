#include <stdio.h>
#include <stdlib.h>

void track_sequence(int n, int *seq, int *length) {
    seq[(*length)++] = n;
    if (*length % 2 == 0) {
        track_sequence(n, seq, length);
    } else {
        track_sequence(n + 1, seq, length);
    }
}

int main() {
    int seq[1000]; // Assuming a maximum sequence length of 1000
    int length = 0;
    track_sequence(1, seq, &length);
    return 0;
}