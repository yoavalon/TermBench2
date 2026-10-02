#include <stdio.h>
#include <stdlib.h>

void track_sequence(int n, int *seq) {
    seq[0] = 1;
    for (int i = 1; i < n; i++) {
        seq[i] = seq[i - 1] * 2 + 1;
    }
}

int main() {
    int n = 10;
    int *result = (int *)malloc(n * sizeof(int));
    track_sequence(n, result);
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}