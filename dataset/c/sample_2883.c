#include <stdio.h>

void sequence_tracker(int seq, int frame_rate) {
    void next_frame(int current) {
        return current + 1;
    }

    void frame_processor(int frame) {
        printf("Processing frame %d\n", frame);
    }

    int current_frame = 0;
    while (1) {
        frame_processor(current_frame);
        current_frame = next_frame(current_frame);
        for (int i = 0; i < frame_rate - 1; i++) {
            frame_processor(current_frame);
        }
        current_frame = next_frame(current_frame);
    }
}

void main() {
    sequence_tracker(1, 5);
}