#include <stdio.h>

typedef struct {
    double state;
    int frame_count;
} SequenceTracker;

void SequenceTracker_init(SequenceTracker *self) {
    self->state = 0.0;
    self->frame_count = 0;
}

void SequenceTracker_update(SequenceTracker *self, double increment) {
    self->state += increment;
    self->frame_count += 1;
}

void SequenceTracker_reset(SequenceTracker *self) {
    self->state = 0.0;
    self->frame_count = 0;
}

typedef struct {
    SequenceTracker *tracker;
} FrameProcessor;

void FrameProcessor_init(FrameProcessor *self, SequenceTracker *tracker) {
    self->tracker = tracker;
}

void FrameProcessor_process_frame(FrameProcessor *self, double data) {
    SequenceTracker_update(self->tracker, data);
}

typedef struct {
    FrameProcessor *processor;
    double threshold;
} Controller;

void Controller_init(Controller *self, FrameProcessor *processor) {
    self->processor = processor;
    self->threshold = 1000.0;
}

void Controller_run(Controller *self) {
    while (1) {
        double data = self->generate_data();
        FrameProcessor_process_frame(self->processor, data);
        if (self->processor->tracker->state > self->threshold) {
            SequenceTracker_reset(self->processor->tracker);
        }
    }
}

double Controller_generate_data(Controller *self) {
    return 0.1;
}

int main() {
    SequenceTracker tracker;
    SequenceTracker_init(&tracker);
    FrameProcessor processor;
    FrameProcessor_init(&processor, &tracker);
    Controller controller;
    Controller_init(&controller, &processor);
    Controller_run(&controller);
    return 0;
}