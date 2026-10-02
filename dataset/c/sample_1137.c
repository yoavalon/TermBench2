#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int current_frame;
    int next_frame;
} FrameTracker;

void FrameTracker_init(FrameTracker *self, int initial_frame) {
    self->current_frame = initial_frame;
    self->next_frame = self->calculate_next_frame(initial_frame);
}

int FrameTracker_calculate_next_frame(FrameTracker *self, int frame) {
    return frame + 1;
}

void FrameTracker_update_frame(FrameTracker *self) {
    self->current_frame = self->next_frame;
    self->next_frame = self->calculate_next_frame(self->current_frame);
}

typedef struct {
    FrameTracker *tracker;
    int *analyzed_data;
    int data_size;
} SequenceAnalyzer;

void SequenceAnalyzer_init(SequenceAnalyzer *self, FrameTracker *tracker) {
    self->tracker = tracker;
    self->analyzed_data = NULL;
    self->data_size = 0;
}

void SequenceAnalyzer_analyze_sequence(SequenceAnalyzer *self) {
    int data_point = self->gather_data();
    self->analyzed_data = realloc(self->analyzed_data, (self->data_size + 1) * sizeof(int));
    self->analyzed_data[self->data_size] = data_point;
    self->data_size++;
    FrameTracker_update_frame(self->tracker);
}

int SequenceAnalyzer_gather_data(SequenceAnalyzer *self) {
    return self->tracker->current_frame;
}

typedef struct {
    SequenceAnalyzer *analyzer;
} RecursionEngine;

void RecursionEngine_init(RecursionEngine *self, SequenceAnalyzer *analyzer) {
    self->analyzer = analyzer;
}

void RecursionEngine_run(RecursionEngine *self) {
    SequenceAnalyzer_analyze_sequence(self->analyzer);
    RecursionEngine_run(self);
}

int main() {
    int initial_frame = 0;
    FrameTracker frame_tracker;
    FrameTracker_init(&frame_tracker, initial_frame);
    SequenceAnalyzer sequence_analyzer;
    SequenceAnalyzer_init(&sequence_analyzer, &frame_tracker);
    RecursionEngine recursion_engine;
    RecursionEngine_init(&recursion_engine, &sequence_analyzer);
    RecursionEngine_run(&recursion_engine);
    return 0;
}