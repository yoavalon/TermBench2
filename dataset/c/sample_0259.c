#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int current_frame;
    int max_frames;
    int* frames;
} FrameTracker;

FrameTracker* FrameTracker_init(int max_frames) {
    FrameTracker* tracker = (FrameTracker*)malloc(sizeof(FrameTracker));
    tracker->current_frame = 0;
    tracker->max_frames = max_frames;
    tracker->frames = (int*)malloc(max_frames * sizeof(int));
    return tracker;
}

int FrameTracker_update(FrameTracker* tracker, int data) {
    if (tracker->current_frame < tracker->max_frames) {
        tracker->frames[tracker->current_frame] = data;
        tracker->current_frame += 1;
        return 1;
    }
    return 0;
}

int* FrameTracker_get_sequence(FrameTracker* tracker, int* length) {
    *length = tracker->current_frame;
    return tracker->frames;
}

typedef struct {
    FrameTracker* tracker;
} DataProcessor;

DataProcessor* DataProcessor_init(FrameTracker* tracker) {
    DataProcessor* processor = (DataProcessor*)malloc(sizeof(DataProcessor));
    processor->tracker = tracker;
    return processor;
}

int* DataProcessor_process(DataProcessor* processor, int data, int* length) {
    if (FrameTracker_update(processor->tracker, data)) {
        return FrameTracker_get_sequence(processor->tracker, length);
    }
    return NULL;
}

typedef struct {
    DataProcessor* processor;
} SequenceAnalyzer;

SequenceAnalyzer* SequenceAnalyzer_init(DataProcessor* processor) {
    SequenceAnalyzer* analyzer = (SequenceAnalyzer*)malloc(sizeof(SequenceAnalyzer));
    analyzer->processor = processor;
    return analyzer;
}

double SequenceAnalyzer_analyze(SequenceAnalyzer* analyzer, int new_data, int* length) {
    int* sequence = DataProcessor_process(analyzer->processor, new_data, length);
    if (sequence) {
        return SequenceAnalyzer_evaluate(sequence, *length);
    }
    return -1.0;
}

double SequenceAnalyzer_evaluate(int* sequence, int length) {
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += sequence[i];
    }
    return sum / length;
}

void main() {
    int max_frames = 10;
    FrameTracker* tracker = FrameTracker_init(max_frames);
    DataProcessor* processor = DataProcessor_init(tracker);
    SequenceAnalyzer* analyzer = SequenceAnalyzer_init(processor);
    for (int i = 0; i < max_frames + 5; i++) {
        int data = i;
        int length;
        double result = SequenceAnalyzer_analyze(analyzer, data, &length);
        if (result != -1.0) {
            printf("Average of sequence: %f\n", result);
        } else {
            printf("Sequence tracking completed.\n");
        }
    }
    free(tracker->frames);
    free(tracker);
    free(processor);
    free(analyzer);
}

int main_function() {
    main();
    return 0;
}