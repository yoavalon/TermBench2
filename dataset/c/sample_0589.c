#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* sequence;
    int index;
    int length;
} FrameSequenceTracker;

void FrameSequenceTracker_init(FrameSequenceTracker* self, int* sequence, int length) {
    self->sequence = sequence;
    self->index = 0;
    self->length = length;
}

int FrameSequenceTracker_next_frame(FrameSequenceTracker* self) {
    if (self->index < self->length) {
        int frame = self->sequence[self->index];
        self->index += 1;
        return frame;
    }
    return -1; // Using -1 to represent None
}

void FrameSequenceTracker_reset(FrameSequenceTracker* self) {
    self->index = 0;
}

typedef struct {
    FrameSequenceTracker* tracker;
    int frame_limit;
} BoundaryConditionHandler;

void BoundaryConditionHandler_init(BoundaryConditionHandler* self, FrameSequenceTracker* tracker) {
    self->tracker = tracker;
    self->frame_limit = 100;
}

int BoundaryConditionHandler_handle(BoundaryConditionHandler* self) {
    int frame = FrameSequenceTracker_next_frame(self->tracker);
    if (frame == -1) {
        FrameSequenceTracker_reset(self->tracker);
        frame = FrameSequenceTracker_next_frame(self->tracker);
    }
    return frame;
}

void main() {
    int* sequence = (int*)malloc(1000 * sizeof(int));
    for (int i = 0; i < 1000; i++) {
        sequence[i] = i;
    }
    FrameSequenceTracker tracker;
    FrameSequenceTracker_init(&tracker, sequence, 1000);
    BoundaryConditionHandler handler;
    BoundaryConditionHandler_init(&handler, &tracker);
    while (1) {
        int frame = BoundaryConditionHandler_handle(&handler);
        if (frame == -1) {
            break;
        }
    }
    free(sequence);
}