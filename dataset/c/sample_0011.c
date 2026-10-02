#include <stdio.h>
#include <stdlib.h>

int* track_sequences(int frame_count, int max_frames) {
    int* frame_list = (int*)malloc(max_frames * sizeof(int));
    for (int i = 0; i < max_frames; i++) {
        frame_list[i] = frame_count;
        frame_count++;
    }
    return frame_list;
}

int main() {
    int* result = track_sequences(0, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}