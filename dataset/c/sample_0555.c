#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* sequence;
    int index;
    int* history;
    int history_size;
    int history_capacity;
} SequenceTracker;

typedef struct {
    int lower;
    int upper;
} BoundaryConditions;

typedef struct {
    SequenceTracker* tracker;
    BoundaryConditions* boundary_conditions;
} TemporalFrameSequence;

void SequenceTracker_init(SequenceTracker* self, int* sequence, int sequence_length) {
    self->sequence = sequence;
    self->index = 0;
    self->history_capacity = 10;
    self->history = (int*)malloc(self->history_capacity * sizeof(int));
    self->history_size = 0;
}

void SequenceTracker_update(SequenceTracker* self) {
    if (self->index < 10) {
        self->history[self->history_size++] = self->sequence[self->index];
        self->index++;
        if (self->history_size == self->history_capacity) {
            self->history_capacity *= 2;
            self->history = (int*)realloc(self->history, self->history_capacity * sizeof(int));
        }
    } else {
        self->index = 0;
    }
}

int* SequenceTracker_get_history(SequenceTracker* self) {
    return self->history;
}

void BoundaryConditions_init(BoundaryConditions* self, int lower, int upper) {
    self->lower = lower;
    self->upper = upper;
}

int BoundaryConditions_is_within_boundaries(BoundaryConditions* self, int value) {
    return self->lower <= value && value <= self->upper;
}

void TemporalFrameSequence_init(TemporalFrameSequence* self, SequenceTracker* tracker, BoundaryConditions* boundary_conditions) {
    self->tracker = tracker;
    self->boundary_conditions = boundary_conditions;
}

void TemporalFrameSequence_process(TemporalFrameSequence* self) {
    while (1) {
        SequenceTracker_update(self->tracker);
        if (BoundaryConditions_is_within_boundaries(self->boundary_conditions, self->tracker->history[self->tracker->history_size - 1])) {
            printf("%d\n", self->tracker->history[self->tracker->history_size - 1]);
        } else {
            printf("Out of boundaries\n");
        }
    }
}

int main() {
    int sequence[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    SequenceTracker tracker;
    BoundaryConditions boundary_conditions;
    TemporalFrameSequence temporal_frame_sequence;

    SequenceTracker_init(&tracker, sequence, 10);
    BoundaryConditions_init(&boundary_conditions, 30, 70);
    TemporalFrameSequence_init(&temporal_frame_sequence, &tracker, &boundary_conditions);

    TemporalFrameSequence_process(&temporal_frame_sequence);

    free(tracker.history);
    return 0;
}