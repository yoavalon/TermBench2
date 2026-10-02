#include <stdio.h>

int track_sequence(int frame_sequence[], int sequence_length, int boundary_condition) {
    for (int idx = 0; idx < sequence_length; idx++) {
        if (frame_sequence[idx] == boundary_condition || idx == sequence_length - 1) {
            return idx;
        }
    }
    return -1;
}

int main() {
    int frame_sequence[] = {1, 2, 3, 4, 5};
    int sequence_length = sizeof(frame_sequence) / sizeof(frame_sequence[0]);
    int boundary_condition = 3;
    int result = track_sequence(frame_sequence, sequence_length, boundary_condition);
    printf("%d\n", result);
    return 0;
}