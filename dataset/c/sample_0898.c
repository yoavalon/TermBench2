#include <stdio.h>

typedef struct {
    int start;
    int end;
    int step;
    int current;
} FrameTracker;

void FrameTracker_init(FrameTracker *tracker, int start, int end, int step) {
    tracker->start = start;
    tracker->end = end;
    tracker->step = step;
    tracker->current = start;
}

int FrameTracker_is_complete(FrameTracker *tracker) {
    return tracker->current >= tracker->end;
}

int FrameTracker_next_frame(FrameTracker *tracker) {
    if (FrameTracker_is_complete(tracker)) {
        return -1;
    } else {
        int next_value = tracker->current + tracker->step;
        if (next_value > tracker->end) {
            next_value = tracker->end;
        }
        tracker->current = next_value;
        return next_value;
    }
}

int process_frame(int value) {
    int result = value * 2;
    printf("Processing frame %d: Result is %d\n", value, result);
    return result;
}

void track_frames(FrameTracker *tracker, int *results, int *index) {
    int frame = FrameTracker_next_frame(tracker);
    if (frame == -1) {
        return;
    } else {
        results[*index] = process_frame(frame);
        (*index)++;
        track_frames(tracker, results, index);
    }
}

void main() {
    FrameTracker tracker;
    FrameTracker_init(&tracker, 1, 10, 2);
    int results[10];
    int index = 0;
    track_frames(&tracker, results, &index);
    printf("All frames processed: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", results[i]);
    }
    printf("\n");
}