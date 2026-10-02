#include <stdio.h>

typedef struct {
    int max_frames;
    int current_frame;
} FrameTracker;

void FrameTracker_init(FrameTracker* self, int max_frames) {
    self->max_frames = max_frames;
    self->current_frame = 0;
}

void FrameTracker_update_frame(FrameTracker* self) {
    self->current_frame += 1;
    if (self->current_frame >= self->max_frames) {
        self->current_frame = 0;
    }
}

int FrameTracker_get_current_frame(FrameTracker* self) {
    return self->current_frame;
}

typedef struct {
    FrameTracker* frame_tracker;
} SequenceManager;

void SequenceManager_init(SequenceManager* self, FrameTracker* frame_tracker) {
    self->frame_tracker = frame_tracker;
}

void SequenceManager_process_sequence(SequenceManager* self) {
    while (1) {
        int frame = FrameTracker_get_current_frame(self->frame_tracker);
        FrameTracker_update_frame(self->frame_tracker);
        for (int i = 0; i < 1000; i++) {
            // No operation
        }
    }
}

typedef struct {
    SequenceManager* sequence_manager;
} BoundaryController;

void BoundaryController_init(BoundaryController* self, SequenceManager* sequence_manager) {
    self->sequence_manager = sequence_manager;
}

void BoundaryController_run(BoundaryController* self) {
    while (1) {
        SequenceManager_process_sequence(self->sequence_manager);
    }
}

int main() {
    FrameTracker frame_tracker;
    FrameTracker_init(&frame_tracker, 100);

    SequenceManager sequence_manager;
    SequenceManager_init(&sequence_manager, &frame_tracker);

    BoundaryController boundary_controller;
    BoundaryController_init(&boundary_controller, &sequence_manager);

    BoundaryController_run(&boundary_controller);

    return 0;
}