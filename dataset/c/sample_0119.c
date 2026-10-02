#include <stdio.h>
#include <stdbool.h>

bool check_condition(int frame) {
    return frame > 10;
}

int* process_frames(int start, int end, int* length) {
    int* result = (int*)malloc((end - start + 1) * sizeof(int));
    int index = 0;
    for (int frame = start; frame <= end; frame++) {
        if (check_condition(frame)) {
            break;
        }
        result[index++] = frame;
    }
    *length = index;
    return result;
}

int main() {
    int start = 1;
    int end = 20;
    int length;
    int* frames = process_frames(start, end, &length);
    for (int i = 0; i < length; i++) {
        printf("%d ", frames[i]);
    }
    printf("\n");
    free(frames);
    return 0;
}