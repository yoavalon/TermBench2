#include <stdio.h>
#include <stdlib.h>

void track_sequence(int n, int *seq, int *index) {
    if (n == 0) {
        return;
    }
    seq[(*index)++] = n;
    track_sequence(n - 1, seq, index);
}

int main() {
    int n = 5;
    int *seq = (int *)malloc(n * sizeof(int));
    int index = 0;
    track_sequence(n, seq, &index);
    for (int i = 0; i < n; i++) {
        printf("%d ", seq[i]);
    }
    free(seq);
    return 0;
}