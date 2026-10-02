#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int precision;
    int sequence_size;
    int sequence_capacity;
    int **sequence;
} FrameSequenceTracker;

FrameSequenceTracker* create_tracker(int precision) {
    FrameSequenceTracker *tracker = (FrameSequenceTracker *)malloc(sizeof(FrameSequenceTracker));
    tracker->precision = precision;
    tracker->sequence_size = 0;
    tracker->sequence_capacity = 10;
    tracker->sequence = (int **)malloc(tracker->sequence_capacity * sizeof(int *));
    return tracker;
}

void add_frame(FrameSequenceTracker *tracker, int timestamp, double value) {
    if (tracker->sequence_size == tracker->sequence_capacity) {
        tracker->sequence_capacity *= 2;
        tracker->sequence = (int **)realloc(tracker->sequence, tracker->sequence_capacity * sizeof(int *));
    }
    tracker->sequence[tracker->sequence_size] = (int *)malloc(2 * sizeof(int));
    tracker->sequence[tracker->sequence_size][0] = timestamp;
    tracker->sequence[tracker->sequence_size][1] = (int)(value * pow(10, tracker->precision) + 0.5);
    tracker->sequence_size++;
}

int* calculate_difference(FrameSequenceTracker *tracker) {
    int *differences = (int *)malloc((tracker->sequence_size - 1) * sizeof(int));
    for (int i = 1; i < tracker->sequence_size; i++) {
        int prev_value = tracker->sequence[i - 1][1];
        int curr_value = tracker->sequence[i][1];
        differences[i - 1] = abs(curr_value - prev_value);
    }
    return differences;
}

int* analyze(FrameSequenceTracker *tracker) {
    int *differences = calculate_difference(tracker);
    int max_diff = 0, min_diff = 0, avg_diff = 0;
    if (tracker->sequence_size > 1) {
        max_diff = differences[0];
        min_diff = differences[0];
        for (int i = 0; i < tracker->sequence_size - 1; i++) {
            if (differences[i] > max_diff) max_diff = differences[i];
            if (differences[i] < min_diff) min_diff = differences[i];
            avg_diff += differences[i];
        }
        avg_diff /= (tracker->sequence_size - 1);
    }
    int *results = (int *)malloc(3 * sizeof(int));
    results[0] = max_diff;
    results[1] = min_diff;
    results[2] = avg_diff;
    free(differences);
    return results;
}

void generate_sequence(FrameSequenceTracker *tracker, int start, int end, int step) {
    int timestamp = start;
    while (timestamp <= end) {
        double value = timestamp * 0.123456789;
        add_frame(tracker, timestamp, value);
        timestamp += step;
    }
}

int main() {
    FrameSequenceTracker *tracker = create_tracker(5);
    generate_sequence(tracker, 0, 100, 1);
    int *results = analyze(tracker);
    printf("Max Difference: %d, Min Difference: %d, Average Difference: %d\n", results[0], results[1], results[2]);
    free(results);
    for (int i = 0; i < tracker->sequence_size; i++) {
        free(tracker->sequence[i]);
    }
    free(tracker->sequence);
    free(tracker);
    return 0;
}