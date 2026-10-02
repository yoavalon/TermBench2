#include <stdio.h>
#include <stdlib.h>

void track_frames(int n, int* seq, int* index) {
    if (n == 0) {
        return;
    }
    seq[(*index)++] = n;
    track_frames(n - 1, seq, index);
}

int main() {
    int n = 5;
    int* seq = (int*)malloc(n * sizeof(int));
    int index = 0;
    track_frames(n, seq, &index);
    for (int i = 0; i < index; i++) {
        printf("%d ", seq[i]);
    }
    free(seq);
    return 0;
}