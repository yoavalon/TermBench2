#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FrameTracker {
    char** sequence;
    int current;
} FrameTracker;

FrameTracker* FrameTracker_init(char** sequence, int current) {
    FrameTracker* self = (FrameTracker*)malloc(sizeof(FrameTracker));
    self->sequence = sequence;
    self->current = current;
    return self;
}

FrameTracker* FrameTracker_next_frame(FrameTracker* self) {
    if (self->current < 4) {
        return FrameTracker_init(self->sequence, self->current + 1);
    }
    return NULL;
}

char* FrameTracker_get_frame(FrameTracker* self) {
    return self->sequence[self->current];
}

typedef struct FrameProcessor {
    FrameTracker* tracker;
} FrameProcessor;

FrameProcessor* FrameProcessor_init(FrameTracker* tracker) {
    FrameProcessor* self = (FrameProcessor*)malloc(sizeof(FrameProcessor));
    self->tracker = tracker;
    return self;
}

char* FrameProcessor_process(FrameProcessor* self) {
    char* frame = FrameTracker_get_frame(self->tracker);
    char* result = (char*)malloc(100 * sizeof(char));
    sprintf(result, "Processed %s", frame);
    return result;
}

typedef struct SequenceAnalyzer {
    FrameProcessor* processor;
} SequenceAnalyzer;

SequenceAnalyzer* SequenceAnalyzer_init(FrameProcessor* processor) {
    SequenceAnalyzer* self = (SequenceAnalyzer*)malloc(sizeof(SequenceAnalyzer));
    self->processor = processor;
    return self;
}

char* SequenceAnalyzer_analyze(SequenceAnalyzer* self) {
    char* result = FrameProcessor_process(self->processor);
    FrameTracker* tracker = FrameTracker_next_frame(self->processor->tracker);
    if (tracker) {
        char* next_result = SequenceAnalyzer_analyze(SequenceAnalyzer_init(FrameProcessor_init(tracker)));
        char* combined = (char*)malloc(strlen(result) + strlen(next_result) + 2 * sizeof(char));
        sprintf(combined, "%s\n%s", result, next_result);
        free(result);
        free(next_result);
        return combined;
    }
    return result;
}

void main() {
    char* sequence[] = {"frame1", "frame2", "frame3", "frame4", "frame5"};
    FrameTracker* tracker = FrameTracker_init(sequence, 0);
    FrameProcessor* processor = FrameProcessor_init(tracker);
    SequenceAnalyzer* analyzer = SequenceAnalyzer_init(processor);
    printf("%s\n", SequenceAnalyzer_analyze(analyzer));
}