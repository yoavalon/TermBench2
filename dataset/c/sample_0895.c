#include <stdio.h>

typedef struct {
    int* sequence;
    int index;
} FrameTracker;

FrameTracker* FrameTracker_new(int* sequence, int index) {
    FrameTracker* tracker = (FrameTracker*)malloc(sizeof(FrameTracker));
    tracker->sequence = sequence;
    tracker->index = index;
    return tracker;
}

int next_frame(FrameTracker* tracker) {
    if (tracker->index < 4) {
        tracker->index += 1;
    }
    return tracker->sequence[tracker->index];
}

int previous_frame(FrameTracker* tracker) {
    if (tracker->index > 0) {
        tracker->index -= 1;
    }
    return tracker->sequence[tracker->index];
}

int current_frame(FrameTracker* tracker) {
    return tracker->sequence[tracker->index];
}

int process_frame(int frame) {
    return frame + 1;
}

void track_sequence(FrameTracker* tracker, char* direction, int count) {
    if (count > 0) {
        int new_frame;
        if (strcmp(direction, "forward") == 0) {
            new_frame = next_frame(tracker);
        } else {
            new_frame = previous_frame(tracker);
        }
        int processed_frame = process_frame(new_frame);
        printf("%d\n", processed_frame);
        track_sequence(tracker, direction, count - 1);
    }
}

void main() {
    int sequence[] = {10, 20, 30, 40, 50};
    FrameTracker* tracker = FrameTracker_new(sequence, 0);
    track_sequence(tracker, "forward", 3);
    track_sequence(tracker, "backward", 2);
    free(tracker);
}