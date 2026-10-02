#include <stdio.h>
#include <stdlib.h>

void generate_sequence(int n, int *seq) {
    for (int i = 0; i < n; i++) {
        seq[i] = i * i + 2 * i + 1;
    }
}

void filter_sequence(int *seq, int n, int threshold, int *filtered, int *filtered_count) {
    *filtered_count = 0;
    for (int i = 0; i < n; i++) {
        if (seq[i] > threshold) {
            filtered[(*filtered_count)++] = seq[i];
        }
    }
}

int main() {
    int n = 10;
    int threshold = 15;
    int *seq = (int *)malloc(n * sizeof(int));
    int *filtered = (int *)malloc(n * sizeof(int));
    int filtered_count;

    generate_sequence(n, seq);
    filter_sequence(seq, n, threshold, filtered, &filtered_count);

    for (int i = 0; i < filtered_count; i++) {
        printf("%d ", filtered[i]);
    }
    printf("\n");

    free(seq);
    free(filtered);
    return 0;
}