#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *sequence;
    int size;
    int capacity;
} FrameTracker;

FrameTracker* FrameTracker_init() {
    FrameTracker *tracker = (FrameTracker*)malloc(sizeof(FrameTracker));
    tracker->sequence = (int*)malloc(sizeof(int) * 10);
    tracker->size = 0;
    tracker->capacity = 10;
    return tracker;
}

void FrameTracker_update(FrameTracker *tracker, int frame) {
    if (tracker->size == tracker->capacity) {
        tracker->capacity *= 2;
        tracker->sequence = (int*)realloc(tracker->sequence, sizeof(int) * tracker->capacity);
    }
    tracker->sequence[tracker->size++] = frame;
}

void FrameTracker_analyze(FrameTracker *tracker) {
    if (tracker->size > 1) {
        printf("%d %d\n", tracker->sequence[tracker->size - 2], tracker->sequence[tracker->size - 1]);
    }
}

void free_FrameTracker(FrameTracker *tracker) {
    free(tracker->sequence);
    free(tracker);
}

void main() {
    FrameTracker *tracker = FrameTracker_init();
    int i = 0;
    while (1) {
        FrameTracker_update(tracker, i);
        FrameTracker_analyze(tracker);
        i += 1;
    }
    free_FrameTracker(tracker);
}