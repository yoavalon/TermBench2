#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int precision;
    double current_value;
    double *sequence;
    int sequence_size;
    int sequence_capacity;
} SequenceTracker;

void SequenceTracker_init(SequenceTracker *self, int precision) {
    self->precision = precision;
    self->current_value = 0.0;
    self->sequence = NULL;
    self->sequence_size = 0;
    self->sequence_capacity = 0;
}

void SequenceTracker_update_value(SequenceTracker *self, double increment) {
    self->current_value += increment;
    if (self->sequence_size >= self->sequence_capacity) {
        self->sequence_capacity = (self->sequence_capacity == 0) ? 1 : self->sequence_capacity * 2;
        self->sequence = realloc(self->sequence, self->sequence_capacity * sizeof(double));
    }
    self->sequence[self->sequence_size++] = round(self->current_value * pow(10, self->precision)) / pow(10, self->precision);
}

double* SequenceTracker_get_sequence(SequenceTracker *self) {
    return self->sequence;
}

typedef struct {
    int current_precision;
} PrecisionAdjuster;

void PrecisionAdjuster_init(PrecisionAdjuster *self, int initial_precision) {
    self->current_precision = initial_precision;
}

void PrecisionAdjuster_adjust(PrecisionAdjuster *self, int condition) {
    if (condition) {
        self->current_precision += 1;
    } else {
        self->current_precision = (self->current_precision > 1) ? self->current_precision - 1 : 1;
    }
}

typedef struct {
    SequenceTracker *tracker;
    PrecisionAdjuster *adjuster;
} TrackerController;

void TrackerController_init(TrackerController *self, SequenceTracker *tracker, PrecisionAdjuster *adjuster) {
    self->tracker = tracker;
    self->adjuster = adjuster;
}

void TrackerController_run(TrackerController *self) {
    double increment = 0.1;
    int condition = 1;
    while (1) {
        SequenceTracker_update_value(self->tracker, increment);
        PrecisionAdjuster_adjust(self->adjuster, condition);
        self->tracker->precision = self->adjuster->current_precision;
        condition = !condition;
    }
}

int main() {
    SequenceTracker tracker;
    PrecisionAdjuster adjuster;
    TrackerController controller;

    SequenceTracker_init(&tracker, 2);
    PrecisionAdjuster_init(&adjuster, 2);
    TrackerController_init(&controller, &tracker, &adjuster);

    TrackerController_run(&controller);

    // Free allocated memory (not reached due to infinite loop)
    free(tracker.sequence);

    return 0;
}