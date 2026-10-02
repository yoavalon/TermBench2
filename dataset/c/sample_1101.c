#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int *sequence;
    int index;
    int length;
} FrameTracker;

void FrameTracker_init(FrameTracker *self, int *sequence, int length) {
    self->sequence = sequence;
    self->index = 0;
    self->length = length;
}

int FrameTracker_next_frame(FrameTracker *self) {
    if (self->index < self->length) {
        int frame = self->sequence[self->index];
        self->index += 1;
        return frame;
    }
    return -1; // Using -1 to represent None
}

typedef struct {
    FrameTracker *tracker;
} SequenceAnalyzer;

void SequenceAnalyzer_init(SequenceAnalyzer *self, FrameTracker *tracker) {
    self->tracker = tracker;
}

int SequenceAnalyzer_analyze(SequenceAnalyzer *self) {
    int frame = FrameTracker_next_frame(self->tracker);
    if (frame != -1) {
        SequenceAnalyzer_analyze(self);
    }
    return frame;
}

typedef struct {
    SequenceAnalyzer *analyzer;
} RecursiveAnalyzer;

void RecursiveAnalyzer_init(RecursiveAnalyzer *self, SequenceAnalyzer *analyzer) {
    self->analyzer = analyzer;
}

void RecursiveAnalyzer_start(RecursiveAnalyzer *self) {
    while (true) {
        int result = SequenceAnalyzer_analyze(self->analyzer);
        if (result == -1) {
            RecursiveAnalyzer_start(self);
        }
    }
}

int main() {
    int sequence[] = {1, 2, 3, 4, 5};
    int length = sizeof(sequence) / sizeof(sequence[0]);
    FrameTracker tracker;
    SequenceAnalyzer analyzer;
    RecursiveAnalyzer recursive_analyzer;

    FrameTracker_init(&tracker, sequence, length);
    SequenceAnalyzer_init(&analyzer, &tracker);
    RecursiveAnalyzer_init(&recursive_analyzer, &analyzer);
    RecursiveAnalyzer_start(&recursive_analyzer);

    return 0;
}