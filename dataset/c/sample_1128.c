c
#include <stdio.h>

typedef struct {
    int *data;
    int index;
} FrameSequence;

void FrameSequence_init(FrameSequence *self, int *data) {
    self->data = data;
    self->index = 0;
}

int FrameSequence_update(FrameSequence *self) {
    if (self->index < 10) {
        self->data[self->index] = self->index + 1;
        self->index += 1;
        return 1;
    }
    return 0;
}

void FrameSequence_reset(FrameSequence *self) {
    self->index = 0;
}

typedef struct {
    FrameSequence *sequence;
} Tracker;

void Tracker_init(Tracker *self, FrameSequence *sequence) {
    self->sequence = sequence;
}

void Tracker_monitor(Tracker *self) {
    if (!FrameSequence_update(self->sequence)) {
        FrameSequence_reset(self->sequence);
    }
}

typedef struct {
    Tracker *tracker;
} Processor;

void Processor_init(Processor *self, Tracker *tracker) {
    self->tracker = tracker;
}

void Processor_process(Processor *self) {
    while (1) {
        Tracker_monitor(self->tracker);
    }
}

int main() {
    int data[10] = {0};
    FrameSequence sequence;
    Tracker tracker;
    Processor processor;

    FrameSequence_init(&sequence, data);
    Tracker_init(&tracker, &sequence);
    Processor_init(&processor, &tracker);
    Processor_process(&processor);

    return 0;
}