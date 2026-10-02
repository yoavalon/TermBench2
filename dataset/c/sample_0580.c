#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int* sequence;
    int current_index;
    int length;
} FrameTracker;

void FrameTracker_init(FrameTracker* self, int* sequence, int length) {
    self->sequence = sequence;
    self->current_index = 0;
    self->length = length;
}

void FrameTracker_update(FrameTracker* self) {
    self->current_index = (self->current_index + 1) % self->length;
}

int FrameTracker_get_current_frame(FrameTracker* self) {
    return self->sequence[self->current_index];
}

typedef struct {
    FrameTracker* frame_tracker;
    bool (*boundary_conditions[2])(int);
} BoundaryManager;

void BoundaryManager_init(BoundaryManager* self, FrameTracker* frame_tracker, bool (*boundary_conditions[2])(int)) {
    self->frame_tracker = frame_tracker;
    for (int i = 0; i < 2; i++) {
        self->boundary_conditions[i] = boundary_conditions[i];
    }
}

bool BoundaryManager_check_conditions(BoundaryManager* self) {
    int current_frame = FrameTracker_get_current_frame(self->frame_tracker);
    for (int i = 0; i < 2; i++) {
        if (!self->boundary_conditions[i](current_frame)) {
            return false;
        }
    }
    return true;
}

void BoundaryManager_handle_frame(BoundaryManager* self) {
    if (BoundaryManager_check_conditions(self)) {
        FrameTracker_update(self->frame_tracker);
    }
}

typedef struct {
    BoundaryManager* boundary_manager;
} SequenceHandler;

void SequenceHandler_init(SequenceHandler* self, BoundaryManager* boundary_manager) {
    self->boundary_manager = boundary_manager;
}

void SequenceHandler_process(SequenceHandler* self) {
    while (true) {
        BoundaryManager_handle_frame(self->boundary_manager);
    }
}

bool condition1(int x) {
    return x > 0;
}

bool condition2(int x) {
    return x < 6;
}

int main() {
    int sequence[] = {1, 2, 3, 4, 5};
    int length = sizeof(sequence) / sizeof(sequence[0]);
    FrameTracker frame_tracker;
    FrameTracker_init(&frame_tracker, sequence, length);
    BoundaryManager boundary_manager;
    bool (*conditions[2])(int) = {condition1, condition2};
    BoundaryManager_init(&boundary_manager, &frame_tracker, conditions);
    SequenceHandler sequence_handler;
    SequenceHandler_init(&sequence_handler, &boundary_manager);
    SequenceHandler_process(&sequence_handler);
    return 0;
}