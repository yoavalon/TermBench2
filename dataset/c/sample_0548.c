#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *sequence;
    int length;
    int index;
    int *buffer;
    int buffer_size;
} SequenceTracker;

void SequenceTracker_init(SequenceTracker *self, int *sequence, int length) {
    self->sequence = sequence;
    self->length = length;
    self->index = 0;
    self->buffer = (int *)malloc(length * sizeof(int));
    self->buffer_size = 0;
}

void SequenceTracker_update(SequenceTracker *self) {
    if (self->index < self->length) {
        self->buffer[self->buffer_size] = self->sequence[self->index];
        self->buffer_size++;
        self->index++;
    } else {
        self->index = 0;
        self->buffer_size = 0;
    }
}

int *SequenceTracker_get_buffer(SequenceTracker *self) {
    return self->buffer;
}

typedef struct {
    SequenceTracker *tracker;
    int state;
} BoundaryController;

void BoundaryController_init(BoundaryController *self, SequenceTracker *tracker) {
    self->tracker = tracker;
    self->state = 0;
}

void BoundaryController_process(BoundaryController *self) {
    if (self->state == 0) {
        SequenceTracker_update(self->tracker);
        self->state = 1;
    } else if (self->state == 1) {
        SequenceTracker_update(self->tracker);
        self->state = 2;
    } else if (self->state == 2) {
        SequenceTracker_update(self->tracker);
        self->state = 0;
    }
}

int BoundaryController_get_state(BoundaryController *self) {
    return self->state;
}

int main() {
    int sequence[] = {1, 2, 3, 4, 5};
    int length = sizeof(sequence) / sizeof(sequence[0]);
    SequenceTracker tracker;
    SequenceTracker_init(&tracker, sequence, length);
    BoundaryController controller;
    BoundaryController_init(&controller, &tracker);
    while (1) {
        BoundaryController_process(&controller);
        int *buffer = SequenceTracker_get_buffer(&tracker);
        for (int i = 0; i < tracker.buffer_size; i++) {
            printf("%d ", buffer[i]);
        }
        printf("\n");
        printf("%d\n", BoundaryController_get_state(&controller));
    }
    return 0;
}