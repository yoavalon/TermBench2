#include <stdio.h>

typedef struct {
    int value;
    int increment;
    int max_iterations;
    int current_iteration;
} SequenceTracker;

void SequenceTracker_init(SequenceTracker *self, int initial_value, int increment, int max_iterations) {
    self->value = initial_value;
    self->increment = increment;
    self->max_iterations = max_iterations;
    self->current_iteration = 0;
}

int SequenceTracker_next(SequenceTracker *self) {
    if (self->current_iteration < self->max_iterations) {
        self->value += self->increment;
        self->current_iteration += 1;
        return self->value;
    } else {
        return -1; // Using -1 to represent None
    }
}

typedef struct {
    int completed;
} SequenceObserver;

void SequenceObserver_init(SequenceObserver *self) {
    self->completed = 0;
}

void SequenceObserver_on_next(SequenceObserver *self, int value) {
    printf("Current value: %d\n", value);
}

void SequenceObserver_complete(SequenceObserver *self) {
    printf("Sequence tracking completed.\n");
}

void monitor_sequence(SequenceTracker *tracker, SequenceObserver *observer) {
    while (1) {
        int result = SequenceTracker_next(tracker);
        if (result == -1) {
            SequenceObserver_complete(observer);
            break;
        } else {
            SequenceObserver_on_next(observer, result);
        }
    }
}

void main() {
    SequenceTracker tracker;
    SequenceObserver observer;
    SequenceTracker_init(&tracker, 0, 1, 10);
    SequenceObserver_init(&observer);
    monitor_sequence(&tracker, &observer);
}