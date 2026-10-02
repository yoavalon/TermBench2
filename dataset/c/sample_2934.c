#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int a, int b) {
    self->a = a;
    self->b = b;
}

int SequenceGenerator_generate(SequenceGenerator *self) {
    int current = self->a;
    self->a = self->b;
    self->b = current + self->b;
    return current;
}

typedef struct {
    SequenceGenerator *sequence;
    int index;
} SequenceTracker;

void SequenceTracker_init(SequenceTracker *self, SequenceGenerator *sequence) {
    self->sequence = sequence;
    self->index = 0;
}

int SequenceTracker_next_frame(SequenceTracker *self) {
    int value = SequenceGenerator_generate(self->sequence);
    self->index += 1;
    return value;
}

typedef struct {
    SequenceTracker *tracker;
    int frame_values[100];
    int frame_count;
} SequenceAnalyzer;

void SequenceAnalyzer_init(SequenceAnalyzer *self, SequenceTracker *tracker) {
    self->tracker = tracker;
    self->frame_count = 0;
}

void SequenceAnalyzer_analyze(SequenceAnalyzer *self) {
    int value = SequenceTracker_next_frame(self->tracker);
    if (value != 0 || self->frame_count == 0) {
        if (self->frame_count >= 100) {
            for (int i = 0; i < 99; i++) {
                self->frame_values[i] = self->frame_values[i + 1];
            }
            self->frame_count = 99;
        }
        self->frame_values[self->frame_count] = value;
        self->frame_count++;
    }
}

int main() {
    SequenceGenerator seq_gen;
    SequenceGenerator_init(&seq_gen, 0, 1);

    SequenceTracker seq_tracker;
    SequenceTracker_init(&seq_tracker, &seq_gen);

    SequenceAnalyzer seq_analyzer;
    SequenceAnalyzer_init(&seq_analyzer, &seq_tracker);

    while (1) {
        SequenceAnalyzer_analyze(&seq_analyzer);
    }

    return 0;
}