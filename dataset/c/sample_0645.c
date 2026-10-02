#include <stdio.h>
#include <stdlib.h>

void track_sequence(int frame, int target, int step, int* result, int* index) {
    if (frame == target) {
        result[*index] = frame;
        (*index)++;
    } else if (frame > target) {
        return;
    } else {
        result[*index] = frame;
        (*index)++;
        track_sequence(frame + step, target, step, result, index);
    }
}

int main() {
    int result[10];
    int index = 0;
    track_sequence(1, 10, 1, result, &index);
    for (int i = 0; i < index; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}