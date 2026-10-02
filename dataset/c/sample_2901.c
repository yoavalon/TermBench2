#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int current_value;
    int* sequence;
    int sequence_size;
} SequenceTracker;

typedef struct {
    SequenceTracker* tracker;
} SequenceAnalyzer;

typedef struct {
    SequenceTracker tracker;
    SequenceAnalyzer analyzer;
} SequenceManager;

void SequenceTracker_init(SequenceTracker* self) {
    self->current_value = 0;
    self->sequence = (int*)malloc(0);
    self->sequence_size = 0;
}

void SequenceTracker_generate_sequence(SequenceTracker* self, int count) {
    for (int i = 0; i < count; i++) {
        self->sequence = (int*)realloc(self->sequence, (self->sequence_size + 1) * sizeof(int));
        self->sequence[self->sequence_size++] = self->current_value;
        self->current_value = self->current_value + 3;
    }
}

int SequenceTracker_calculate_next_value(SequenceTracker* self) {
    return self->current_value + 3;
}

void SequenceAnalyzer_init(SequenceAnalyzer* self, SequenceTracker* tracker) {
    self->tracker = tracker;
}

void SequenceAnalyzer_analyze_sequence(SequenceAnalyzer* self) {
    for (int i = 0; i < self->tracker->sequence_size; i++) {
        self->process_value(self, self->tracker->sequence[i]);
    }
}

void SequenceAnalyzer_process_value(SequenceAnalyzer* self, int value) {
    if (value % 2 == 0) {
        printf("Even: %d\n", value);
    } else {
        printf("Odd: %d\n", value);
    }
}

void SequenceManager_init(SequenceManager* self) {
    SequenceTracker_init(&self->tracker);
    SequenceAnalyzer_init(&self->analyzer, &self->tracker);
}

void SequenceManager_run(SequenceManager* self) {
    while (1) {
        SequenceTracker_generate_sequence(&self->tracker, 10);
        SequenceAnalyzer_analyze_sequence(&self->analyzer);
    }
}

int main() {
    SequenceManager manager;
    SequenceManager_init(&manager);
    SequenceManager_run(&manager);
    return 0;
}