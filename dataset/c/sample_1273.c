#include <stdio.h>
#include <stdlib.h>

void sequence_tracker(int frame_count, int max_frames, int *result) {
    for (int i = 0; i < frame_count; i++) {
        result[i] = i;
        if (i >= max_frames - 1) {
            break;
        }
    }
}

int main() {
    int result[5];
    sequence_tracker(10, 5, result);
    for (int i = 0; i < 5; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}