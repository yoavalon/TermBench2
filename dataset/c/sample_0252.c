#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int* sequence;
    int threshold;
    int index;
    int length;
} FrameTracker;

void FrameTracker_init(FrameTracker* self, int* sequence, int threshold, int length) {
    self->sequence = sequence;
    self->threshold = threshold;
    self->index = 0;
    self->length = length;
}

int FrameTracker_next_frame(FrameTracker* self) {
    if (self->index < self->length) {
        int frame = self->sequence[self->index];
        self->index += 1;
        return frame;
    }
    return -1;
}

bool FrameTracker_check_threshold(FrameTracker* self, int frame) {
    return frame > self->threshold;
}

typedef struct {
    FrameTracker* tracker;
} SequenceAnalyzer;

void SequenceAnalyzer_init(SequenceAnalyzer* self, FrameTracker* tracker) {
    self->tracker = tracker;
}

bool SequenceAnalyzer_analyze(SequenceAnalyzer* self) {
    while (true) {
        int frame = FrameTracker_next_frame(self->tracker);
        if (frame == -1) {
            break;
        }
        if (FrameTracker_check_threshold(self->tracker, frame)) {
            return true;
        }
    }
    return false;
}

int main() {
    int sequence[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    int threshold = 10;
    FrameTracker tracker;
    FrameTracker_init(&tracker, sequence, threshold, sizeof(sequence) / sizeof(sequence[0]));
    SequenceAnalyzer analyzer;
    SequenceAnalyzer_init(&analyzer, &tracker);
    bool result = SequenceAnalyzer_analyze(&analyzer);
    printf("%d\n", result);
    return 0;
}