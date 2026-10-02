#include <stdio.h>
#include <stdlib.h>

void generate_sequence(int n, int *sequence) {
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        sequence[i] = a;
        int next = a + b;
        a = b;
        b = next;
    }
}

void track_frames(int *sequence, int n) {
    int frame = 0;
    while (1) {
        printf("Frame %d: ", frame);
        for (int i = 0; i < n; i++) {
            printf("%d", sequence[i]);
            if (i < n - 1) {
                printf(", ");
            }
        }
        printf("\n");
        frame++;
    }
}

int main() {
    int n = 10;
    int *sequence = (int *)malloc(n * sizeof(int));
    generate_sequence(n, sequence);
    track_frames(sequence, n);
    free(sequence);
    return 0;
}