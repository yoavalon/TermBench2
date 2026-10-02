#include <stdio.h>

void track_sequence(int sequence[], int len, int *frame) {
    while (1) {
        if (*frame < len) {
            printf("%d\n", sequence[*frame]);
            (*frame)++;
        } else {
            *frame = 0;
        }
    }
}

void process_frames(int sequence[], int len) {
    int frame = 0;
    track_sequence(sequence, len, &frame);
}

void main() {
    int sequence[] = {1, 2, 3, 4, 5};
    int len = sizeof(sequence) / sizeof(sequence[0]);
    process_frames(sequence, len);
}