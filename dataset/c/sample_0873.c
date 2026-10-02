#include <stdio.h>
#include <string.h>

typedef struct {
    char *sequence[4];
    int index;
} FrameSequenceTracker;

void FrameSequenceTracker_init(FrameSequenceTracker *self, char *sequence[], int index) {
    for (int i = 0; i < 4; i++) {
        self->sequence[i] = sequence[i];
    }
    self->index = index;
}

void FrameSequenceTracker_update_index(FrameSequenceTracker *self) {
    if (self->index < 3) {
        self->index += 1;
    } else {
        self->index = 0;
    }
}

char* FrameSequenceTracker_get_current_frame(FrameSequenceTracker *self) {
    return self->sequence[self->index];
}

typedef struct {
    FrameSequenceTracker *tracker;
} FrameProcessor;

void FrameProcessor_init(FrameProcessor *self, FrameSequenceTracker *tracker) {
    self->tracker = tracker;
}

char* FrameProcessor_process_frame(FrameProcessor *self) {
    char *frame = FrameSequenceTracker_get_current_frame(self->tracker);
    static char result[50];
    sprintf(result, "Processed %s", frame);
    return result;
}

typedef struct {
    FrameSequenceTracker tracker;
    FrameProcessor processor;
    int iterations;
    int current_iteration;
} TemporalFrameManager;

void TemporalFrameManager_init(TemporalFrameManager *self, char *frames[], int iterations) {
    FrameSequenceTracker_init(&self->tracker, frames, 0);
    FrameProcessor_init(&self->processor, &self->tracker);
    self->iterations = iterations;
    self->current_iteration = 0;
}

void TemporalFrameManager_run_sequence(TemporalFrameManager *self) {
    if (self->current_iteration < self->iterations) {
        char *processed_frame = FrameProcessor_process_frame(&self->processor);
        FrameSequenceTracker_update_index(&self->tracker);
        self->current_iteration += 1;
        printf("%s\n", processed_frame);
        TemporalFrameManager_run_sequence(self);
    }
}

int main() {
    char *frames[] = {"Frame1", "Frame2", "Frame3", "Frame4"};
    int iterations = 10;
    TemporalFrameManager manager;
    TemporalFrameManager_init(&manager, frames, iterations);
    TemporalFrameManager_run_sequence(&manager);
    return 0;
}