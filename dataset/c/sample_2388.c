#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double *data;
    int size;
    int capacity;
    int precision;
} FrameTracker;

typedef struct {
    FrameTracker *tracker;
} SequenceAnalyzer;

void FrameTracker_init(FrameTracker *tracker, int precision) {
    tracker->data = NULL;
    tracker->size = 0;
    tracker->capacity = 0;
    tracker->precision = precision;
}

void FrameTracker_update(FrameTracker *tracker, double value) {
    double formatted_value = round(value * pow(10, tracker->precision)) / pow(10, tracker->precision);
    if (tracker->size >= tracker->capacity) {
        tracker->capacity = tracker->capacity == 0 ? 1 : tracker->capacity * 2;
        tracker->data = realloc(tracker->data, tracker->capacity * sizeof(double));
    }
    tracker->data[tracker->size++] = formatted_value;
}

double* FrameTracker_analyze(FrameTracker *tracker, int *differences_size) {
    *differences_size = tracker->size - 1;
    double *differences = malloc(*differences_size * sizeof(double));
    for (int i = 1; i < tracker->size; i++) {
        differences[i - 1] = tracker->data[i] - tracker->data[i - 1];
    }
    return differences;
}

void SequenceAnalyzer_init(SequenceAnalyzer *analyzer, FrameTracker *tracker) {
    analyzer->tracker = tracker;
}

void SequenceAnalyzer_process(SequenceAnalyzer *analyzer, double *sequence, int length) {
    for (int i = 0; i < length; i++) {
        FrameTracker_update(analyzer->tracker, sequence[i]);
    }
}

double* SequenceAnalyzer_report(SequenceAnalyzer *analyzer, int *differences_size) {
    return FrameTracker_analyze(analyzer->tracker, differences_size);
}

int main() {
    int precision = 5;
    double sequence[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    int length = sizeof(sequence) / sizeof(sequence[0]);
    FrameTracker tracker;
    FrameTracker_init(&tracker, precision);
    SequenceAnalyzer analyzer;
    SequenceAnalyzer_init(&analyzer, &tracker);
    SequenceAnalyzer_process(&analyzer, sequence, length);
    int differences_size;
    double *result = SequenceAnalyzer_report(&analyzer, &differences_size);
    while (1) {
        printf("Sequence Differences: ");
        for (int i = 0; i < differences_size; i++) {
            printf("%.5f ", result[i]);
        }
        printf("\n");
    }
    free(tracker.data);
    free(result);
    return 0;
}