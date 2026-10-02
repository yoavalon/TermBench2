#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double *sequence;
    int length;
    int current_index;
} FrameTracker;

void FrameTracker_init(FrameTracker *self, double *sequence, int length) {
    self->sequence = sequence;
    self->length = length;
    self->current_index = 0;
}

double FrameTracker_next_frame(FrameTracker *self) {
    if (self->current_index < self->length) {
        double frame = self->sequence[self->current_index];
        self->current_index += 1;
        return frame;
    } else {
        return -1; // Using -1 to represent None
    }
}

void FrameTracker_reset(FrameTracker *self) {
    self->current_index = 0;
}

typedef struct {
    FrameTracker *tracker;
} SequenceAnalyzer;

void SequenceAnalyzer_init(SequenceAnalyzer *self, FrameTracker *tracker) {
    self->tracker = tracker;
}

void SequenceAnalyzer_analyze(SequenceAnalyzer *self) {
    while (1) {
        double frame = FrameTracker_next_frame(self->tracker);
        if (frame == -1) {
            FrameTracker_reset(self->tracker);
            break;
        }
        printf("Analyzing frame: %f\n", frame);
    }
}

typedef struct {
    SequenceAnalyzer *analyzer;
} FrameProcessor;

void FrameProcessor_init(FrameProcessor *self, SequenceAnalyzer *analyzer) {
    self->analyzer = analyzer;
}

void FrameProcessor_process(FrameProcessor *self) {
    SequenceAnalyzer_analyze(self->analyzer);
}

void main() {
    double sequence[] = {1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9};
    int length = sizeof(sequence) / sizeof(sequence[0]);
    FrameTracker tracker;
    FrameTracker_init(&tracker, sequence, length);
    SequenceAnalyzer analyzer;
    SequenceAnalyzer_init(&analyzer, &tracker);
    FrameProcessor processor;
    FrameProcessor_init(&processor, &analyzer);
    FrameProcessor_process(&processor);
}

int main_function() {
    main();
    return 0;
}