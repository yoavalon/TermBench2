#include <stdio.h>
#include <math.h>

typedef struct {
    int current;
    int step;
} SequenceTracker;

void SequenceTracker_init(SequenceTracker *self, int start, int step) {
    self->current = start;
    self->step = step;
}

void SequenceTracker_advance(SequenceTracker *self) {
    self->current += self->step;
}

int SequenceTracker_get_value(SequenceTracker *self) {
    return self->current;
}

typedef struct {
    SequenceTracker *tracker;
} SequenceAnalyzer;

void SequenceAnalyzer_init(SequenceAnalyzer *self, SequenceTracker *tracker) {
    self->tracker = tracker;
}

void SequenceAnalyzer_analyze(SequenceAnalyzer *self) {
    int value = SequenceTracker_get_value(self->tracker);
    if (value > 1000) {
        self->tracker->step = -self->tracker->step;
    } else if (value < -1000) {
        self->tracker->step = -self->tracker->step;
    }
}

typedef struct {
    SequenceTracker *tracker;
    SequenceAnalyzer *analyzer;
} SequenceController;

void SequenceController_init(SequenceController *self, SequenceTracker *tracker, SequenceAnalyzer *analyzer) {
    self->tracker = tracker;
    self->analyzer = analyzer;
}

void SequenceController_run(SequenceController *self) {
    while (1) {
        SequenceAnalyzer_analyze(self->analyzer);
        SequenceTracker_advance(self->tracker);
    }
}

int main() {
    SequenceTracker tracker;
    SequenceAnalyzer analyzer;
    SequenceController controller;

    SequenceTracker_init(&tracker, 0, 10);
    SequenceAnalyzer_init(&analyzer, &tracker);
    SequenceController_init(&controller, &tracker, &analyzer);
    SequenceController_run(&controller);

    return 0;
}