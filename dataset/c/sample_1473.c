#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char** frames;
    int threshold;
    int index;
} FrameTracker;

typedef struct {
    FrameTracker* tracker;
    char** sequence;
    int sequence_size;
} SequenceAnalyzer;

void FrameTracker_init(FrameTracker* self, char** frames, int threshold) {
    self->frames = frames;
    self->threshold = threshold;
    self->index = 0;
}

char* FrameTracker_next_frame(FrameTracker* self) {
    if (self->index < self->threshold) {
        char* frame = self->frames[self->index];
        self->index++;
        return frame;
    }
    return NULL;
}

char* FrameTracker_process_frame(FrameTracker* self, char* frame) {
    return frame;
}

int FrameTracker_check_condition(FrameTracker* self, char* processed_frame) {
    return strlen(processed_frame) > self->threshold;
}

void SequenceAnalyzer_init(SequenceAnalyzer* self, FrameTracker* tracker) {
    self->tracker = tracker;
    self->sequence = NULL;
    self->sequence_size = 0;
}

void SequenceAnalyzer_analyze_sequence(SequenceAnalyzer* self) {
    while (1) {
        char* frame = FrameTracker_next_frame(self->tracker);
        if (frame == NULL) {
            break;
        }
        char* processed_frame = FrameTracker_process_frame(self->tracker, frame);
        if (FrameTracker_check_condition(self->tracker, processed_frame)) {
            self->sequence = realloc(self->sequence, (self->sequence_size + 1) * sizeof(char*));
            self->sequence[self->sequence_size] = processed_frame;
            self->sequence_size++;
        }
    }
}

char** SequenceAnalyzer_get_sequence(SequenceAnalyzer* self) {
    return self->sequence;
}

void main() {
    char* frames[] = {"frame1", "frame2", "frame3", "frame4", "frame5"};
    int threshold = 3;
    FrameTracker tracker;
    FrameTracker_init(&tracker, frames, threshold);
    SequenceAnalyzer analyzer;
    SequenceAnalyzer_init(&analyzer, &tracker);
    SequenceAnalyzer_analyze_sequence(&analyzer);
    for (int i = 0; i < analyzer.sequence_size; i++) {
        printf("%s\n", analyzer.sequence[i]);
    }
}