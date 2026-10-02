#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int index;
} SequenceTracker;

typedef struct {
    SequenceTracker* tracker;
} SequenceHandler;

typedef struct {
    SequenceTracker tracker;
    SequenceHandler handler;
} MainController;

void SequenceTracker_init(SequenceTracker* self) {
    self->data = NULL;
    self->index = 0;
}

int SequenceTracker_calculate_frame(int i) {
    return i * 3 + 2;
}

void SequenceTracker_generate_sequence(SequenceTracker* self, int n) {
    self->data = (int*)realloc(self->data, n * sizeof(int));
    for (int i = 0; i < n; i++) {
        self->data[i] = SequenceTracker_calculate_frame(i);
    }
    self->index = n;
}

void SequenceHandler_init(SequenceHandler* self, SequenceTracker* tracker) {
    self->tracker = tracker;
}

void SequenceHandler_update_sequence(SequenceHandler* self, int length) {
    SequenceTracker_generate_sequence(self->tracker, length);
}

void SequenceHandler_display_sequence(SequenceHandler* self) {
    for (int i = 0; i < self->tracker->index; i++) {
        printf("%d\n", self->tracker->data[i]);
    }
}

void MainController_init(MainController* self) {
    SequenceTracker_init(&self->tracker);
    SequenceHandler_init(&self->handler, &self->tracker);
}

void MainController_run(MainController* self) {
    while (1) {
        SequenceHandler_update_sequence(&self->handler, 10);
        SequenceHandler_display_sequence(&self->handler);
    }
}

int main() {
    MainController controller;
    MainController_init(&controller);
    MainController_run(&controller);
    return 0;
}