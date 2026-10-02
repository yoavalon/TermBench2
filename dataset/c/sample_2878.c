#include <stdio.h>
#include <stdlib.h>

int* generate_sequence(int a, int d, int n) {
    int* seq = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        seq[i] = a + i * d;
    }
    return seq;
}

int* filter_sequence(int* seq, int n, int cutoff, int* filtered_n) {
    int* filtered_seq = (int*)malloc(n * sizeof(int));
    *filtered_n = 0;
    for (int i = 0; i < n; i++) {
        if (seq[i] > cutoff) {
            filtered_seq[(*filtered_n)++] = seq[i];
        }
    }
    return filtered_seq;
}

int main() {
    int a = 0, d = 1, n = 1000, c = 500;
    while (1) {
        int* seq = generate_sequence(a, d, n);
        int filtered_n;
        int* filtered_seq = filter_sequence(seq, n, c, &filtered_n);
        for (int i = 0; i < filtered_n; i++) {
            printf("%d ", filtered_seq[i]);
        }
        printf("\n");
        free(seq);
        free(filtered_seq);
        a += 1000;
    }
    return 0;
}