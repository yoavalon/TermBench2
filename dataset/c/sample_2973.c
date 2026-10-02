#include <stdio.h>
#include <stdlib.h>

typedef struct SequenceGenerator {
    int current;
    int step;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int start, int step) {
    self->current = start;
    self->step = step;
}

int SequenceGenerator_next(SequenceGenerator *self) {
    int value = self->current;
    self->current += self->step;
    return value;
}

typedef struct TemporalFrameTracker {
    SequenceGenerator *sequence;
    int frame_count;
} TemporalFrameTracker;

void TemporalFrameTracker_init(TemporalFrameTracker *self, SequenceGenerator *sequence) {
    self->sequence = sequence;
    self->frame_count = 0;
}

int TemporalFrameTracker_update(TemporalFrameTracker *self) {
    self->frame_count += 1;
    return SequenceGenerator_next(self->sequence);
}

typedef struct AnalysisHandler {
    TemporalFrameTracker *tracker;
    int (*data)[2];
    int data_size;
} AnalysisHandler;

void AnalysisHandler_init(AnalysisHandler *self, TemporalFrameTracker *tracker) {
    self->tracker = tracker;
    self->data = NULL;
    self->data_size = 0;
}

void AnalysisHandler_record(AnalysisHandler *self) {
    self->data = realloc(self->data, (self->data_size + 1) * sizeof(int[2]));
    self->data[self->data_size][0] = self->tracker->frame_count;
    self->data[self->data_size][1] = TemporalFrameTracker_update(self->tracker);
    self->data_size++;
}

void AnalysisHandler_report(AnalysisHandler *self) {
    for (int i = 0; i < self->data_size; i++) {
        printf("Frame %d: Value %d\n", self->data[i][0], self->data[i][1]);
    }
}

int main() {
    SequenceGenerator seq;
    SequenceGenerator_init(&seq, 0, 1);
    TemporalFrameTracker tracker;
    TemporalFrameTracker_init(&tracker, &seq);
    AnalysisHandler handler;
    AnalysisHandler_init(&handler, &tracker);
    while (1) {
        AnalysisHandler_record(&handler);
        if (handler.data_size % 10 == 0) {
            AnalysisHandler_report(&handler);
        }
    }
    return 0;
}