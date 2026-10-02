#include <stdio.h>

typedef struct {
    int sequence[5][2];
    int index;
    int frame[2];
} FrameTracker;

void FrameTracker_init(FrameTracker *self, int sequence[5][2]) {
    for (int i = 0; i < 5; i++) {
        self->sequence[i][0] = sequence[i][0];
        self->sequence[i][1] = sequence[i][1];
    }
    self->index = 0;
    self->frame[0] = 0;
    self->frame[1] = 0;
}

void FrameTracker_update_frame(FrameTracker *self) {
    if (self->index < 5) {
        self->frame[0] = self->sequence[self->index][0];
        self->frame[1] = self->sequence[self->index][1];
        self->index += 1;
    } else {
        self->frame[0] = 0;
        self->frame[1] = 0;
    }
}

void FrameTracker_get_current_frame(FrameTracker *self, int *frame) {
    frame[0] = self->frame[0];
    frame[1] = self->frame[1];
}

typedef struct {
    FrameTracker *tracker;
} BoundaryChecker;

void BoundaryChecker_init(BoundaryChecker *self, FrameTracker *tracker) {
    self->tracker = tracker;
}

void BoundaryChecker_check_boundaries(BoundaryChecker *self) {
    int frame[2];
    FrameTracker_get_current_frame(self->tracker, frame);
    if (frame[0] != 0 || frame[1] != 0) {
        if (frame[0] < 0 || frame[0] > 100) {
            printf("Boundary exceeded on X-axis\n");
        }
        if (frame[1] < 0 || frame[1] > 100) {
            printf("Boundary exceeded on Y-axis\n");
        }
    }
}

typedef struct {
    FrameTracker tracker;
    BoundaryChecker boundary_checker;
} System;

void System_init(System *self, int sequence[5][2]) {
    FrameTracker_init(&self->tracker, sequence);
    BoundaryChecker_init(&self->boundary_checker, &self->tracker);
}

void System_process_frames(System *self) {
    while (1) {
        FrameTracker_update_frame(&self->tracker);
        BoundaryChecker_check_boundaries(&self->boundary_checker);
    }
}

int main() {
    int sequence[5][2] = {{10, 20}, {50, 50}, {110, 20}, {30, 110}, {10, 20}};
    System system;
    System_init(&system, sequence);
    System_process_frames(&system);
    return 0;
}