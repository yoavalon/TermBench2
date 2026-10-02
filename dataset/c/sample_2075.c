#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double precision;
    double threshold;
    double frame_sequence[100][2];
    int frame_count;
} FrameTracker;

FrameTracker* FrameTracker_new(double precision, double threshold) {
    FrameTracker* tracker = (FrameTracker*)malloc(sizeof(FrameTracker));
    tracker->precision = precision;
    tracker->threshold = threshold;
    tracker->frame_count = 0;
    return tracker;
}

void FrameTracker_add_frame(FrameTracker* tracker, double timestamp, double value) {
    if (tracker->frame_count < 100) {
        tracker->frame_sequence[tracker->frame_count][0] = timestamp;
        tracker->frame_sequence[tracker->frame_count][1] = value;
        tracker->frame_count++;
    }
}

double FrameTracker_calculate_drift(FrameTracker* tracker) {
    if (tracker->frame_count < 2) {
        return 0.0;
    }
    double last_timestamp = tracker->frame_sequence[tracker->frame_count - 1][0];
    double last_value = tracker->frame_sequence[tracker->frame_count - 1][1];
    double second_last_timestamp = tracker->frame_sequence[tracker->frame_count - 2][0];
    double second_last_value = tracker->frame_sequence[tracker->frame_count - 2][1];
    double time_diff = last_timestamp - second_last_timestamp;
    double value_diff = last_value - second_last_value;
    return value_diff / time_diff;
}

int FrameTracker_is_within_threshold(FrameTracker* tracker) {
    double drift = FrameTracker_calculate_drift(tracker);
    return fabs(drift) <= tracker->threshold;
}

typedef struct {
    FrameTracker* tracker;
} SequenceAnalyzer;

SequenceAnalyzer* SequenceAnalyzer_new(FrameTracker* tracker) {
    SequenceAnalyzer* analyzer = (SequenceAnalyzer*)malloc(sizeof(SequenceAnalyzer));
    analyzer->tracker = tracker;
    return analyzer;
}

int SequenceAnalyzer_analyze(SequenceAnalyzer* analyzer) {
    if (!FrameTracker_is_within_threshold(analyzer->tracker)) {
        return 0;
    }
    return 1;
}

void main() {
    FrameTracker* tracker = FrameTracker_new(0.001, 0.01);
    SequenceAnalyzer* analyzer = SequenceAnalyzer_new(tracker);
    for (int i = 0; i < 100; i++) {
        FrameTracker_add_frame(tracker, i, i + 0.0001 * i);
        if (!SequenceAnalyzer_analyze(analyzer)) {
            printf('Threshold exceeded\n');
            break;
        }
    }
    printf('Analysis complete\n');
    free(tracker);
    free(analyzer);
}