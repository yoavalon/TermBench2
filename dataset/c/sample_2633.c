#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int current;
    int end;
    int step;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int start, int end, int step) {
    self->current = start;
    self->end = end;
    self->step = step;
}

int* SequenceGenerator_generate(SequenceGenerator *self, int *size) {
    int capacity = 10; // Initial capacity
    int *sequence = (int *)malloc(capacity * sizeof(int));
    *size = 0;

    while (self->current <= self->end) {
        if (*size >= capacity) {
            capacity *= 2;
            sequence = (int *)realloc(sequence, capacity * sizeof(int));
        }
        sequence[(*size)++] = self->current;
        self->current += self->step;
    }

    return sequence;
}

typedef struct {
    int *sequence;
    int index;
    int size;
} FrameTracker;

void FrameTracker_init(FrameTracker *self, int *sequence, int size) {
    self->sequence = sequence;
    self->index = 0;
    self->size = size;
}

int FrameTracker_next_frame(FrameTracker *self) {
    if (self->index < self->size) {
        int value = self->sequence[self->index];
        self->index++;
        return value;
    }
    return -1; // Using -1 to indicate None
}

typedef struct {
    FrameTracker *tracker;
} TemporalAnalysis;

void TemporalAnalysis_init(TemporalAnalysis *self, FrameTracker *tracker) {
    self->tracker = tracker;
}

int* TemporalAnalysis_analyze(TemporalAnalysis *self, int *size) {
    int capacity = 10; // Initial capacity
    int *result = (int *)malloc(capacity * sizeof(int));
    *size = 0;

    while (1) {
        int frame = FrameTracker_next_frame(self->tracker);
        if (frame == -1) {
            break;
        }
        if (*size >= capacity) {
            capacity *= 2;
            result = (int *)realloc(result, capacity * sizeof(int));
        }
        result[(*size)++] = frame;
    }

    return result;
}

void main() {
    int start = 1;
    int end = 100;
    int step = 5;

    SequenceGenerator generator;
    SequenceGenerator_init(&generator, start, end, step);
    int sequence_size;
    int *sequence = SequenceGenerator_generate(&generator, &sequence_size);

    FrameTracker tracker;
    FrameTracker_init(&tracker, sequence, sequence_size);

    TemporalAnalysis analysis;
    TemporalAnalysis_init(&analysis, &tracker);
    int result_size;
    int *result = TemporalAnalysis_analyze(&analysis, &result_size);

    for (int i = 0; i < result_size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(sequence);
    free(result);
}