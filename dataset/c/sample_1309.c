#include <stdio.h>

void process_sequence(int seq[], int len, int result[]) {
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            result[i] = seq[i] + 1;
        } else {
            result[i] = seq[i] - 1;
        }
    }
}

void track_temporal_frame(int frame[], int len, int final_frame[]) {
    process_sequence(frame, len, final_frame);
}

int main() {
    int initial_frame[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int final_frame[10];
    int len = sizeof(initial_frame) / sizeof(initial_frame[0]);
    track_temporal_frame(initial_frame, len, final_frame);
    for (int i = 0; i < len; i++) {
        printf("%d ", final_frame[i]);
    }
    return 0;
}