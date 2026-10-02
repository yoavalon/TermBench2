#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int frame;
    int* history;
    int history_size;
    int history_capacity;
} FrameSequence;

void FrameSequence_init(FrameSequence* self, int initial_frame) {
    self->frame = initial_frame;
    self->history = NULL;
    self->history_size = 0;
    self->history_capacity = 0;
}

void FrameSequence_update(FrameSequence* self, int new_frame) {
    if (self->history_size >= self->history_capacity) {
        self->history_capacity = self->history_capacity == 0 ? 1 : self->history_capacity * 2;
        self->history = (int*)realloc(self->history, self->history_capacity * sizeof(int));
    }
    self->history[self->history_size++] = self->frame;
    self->frame = new_frame;
}

int* FrameSequence_get_history(FrameSequence* self) {
    return self->history;
}

typedef struct {
    FrameSequence* sequence;
} Tracker;

void Tracker_init(Tracker* self, FrameSequence* sequence) {
    self->sequence = sequence;
}

void Tracker_observe(Tracker* self, int current_frame) {
    FrameSequence_update(self->sequence, current_frame);
}

int* Tracker_retrieve_history(Tracker* self) {
    return FrameSequence_get_history(self->sequence);
}

typedef struct {
    Tracker* tracker;
    int frame;
} Processor;

void Processor_init(Processor* self, Tracker* tracker) {
    self->tracker = tracker;
    self->frame = 0;
}

void Processor_process(Processor* self) {
    while (1) {
        self->frame += 1;
        Tracker_observe(self->tracker, self->frame);
    }
}

int main() {
    int initial_frame = 0;
    FrameSequence sequence;
    FrameSequence_init(&sequence, initial_frame);
    Tracker tracker;
    Tracker_init(&tracker, &sequence);
    Processor processor;
    Processor_init(&processor, &tracker);
    Processor_process(&processor);
    return 0;
}