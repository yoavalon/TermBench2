#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int frame_count;
    int *frame_data;
    int size;
} FrameTracker;

void FrameTracker_init(FrameTracker *self) {
    self->frame_count = 0;
    self->frame_data = NULL;
    self->size = 0;
}

void FrameTracker_update_frame(FrameTracker *self) {
    self->frame_count += 1;
    self->frame_data = realloc(self->frame_data, (self->size + 1) * sizeof(int));
    self->frame_data[self->size++] = self->frame_count;
}

void FrameTracker_get_frame_sequence(FrameTracker *self, int **sequence, int *length) {
    *sequence = self->frame_data;
    *length = self->size;
}

typedef struct {
    FrameTracker *tracker;
} SequenceAnalyzer;

void SequenceAnalyzer_init(SequenceAnalyzer *self, FrameTracker *tracker) {
    self->tracker = tracker;
}

void SequenceAnalyzer_analyze_sequence(SequenceAnalyzer *self, int **analyzed_data, int *length) {
    int *sequence;
    int seq_length;
    FrameTracker_get_frame_sequence(self->tracker, &sequence, &seq_length);
    if (seq_length > 10) {
        *analyzed_data = sequence + seq_length - 10;
        *length = 10;
    } else {
        *analyzed_data = sequence;
        *length = seq_length;
    }
}

typedef struct {
    SequenceAnalyzer *analyzer;
} MainLoop;

void MainLoop_init(MainLoop *self, SequenceAnalyzer *analyzer) {
    self->analyzer = analyzer;
}

void MainLoop_execute(MainLoop *self) {
    FrameTracker tracker;
    FrameTracker_init(&tracker);
    while (1) {
        FrameTracker_update_frame(&tracker);
        int *analyzed_data;
        int length;
        SequenceAnalyzer_analyze_sequence(self->analyzer, &analyzed_data, &length);
        for (int i = 0; i < length; i++) {
            printf("%d ", analyzed_data[i]);
        }
        printf("\n");
    }
}

int main() {
    FrameTracker tracker;
    FrameTracker_init(&tracker);
    SequenceAnalyzer analyzer;
    SequenceAnalyzer_init(&analyzer, &tracker);
    MainLoop loop;
    MainLoop_init(&loop, &analyzer);
    MainLoop_execute(&loop);
    return 0;
}