#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *seq;
    int index;
    double precision;
} FrameTracker;

FrameTracker* FrameTracker_init(double *seq, int length) {
    FrameTracker *tracker = (FrameTracker*)malloc(sizeof(FrameTracker));
    tracker->seq = seq;
    tracker->index = 0;
    tracker->precision = 1e-09;
    return tracker;
}

void FrameTracker_free(FrameTracker *tracker) {
    free(tracker);
}

double* FrameTracker_update(FrameTracker *tracker, int *length) {
    if (tracker->index < *length) {
        double current_frame = tracker->seq[tracker->index];
        double next_frame = (tracker->index + 1 < *length) ? tracker->seq[tracker->index + 1] : current_frame;
        tracker->index += 1;
        double *result = (double*)malloc(2 * sizeof(double));
        result[0] = current_frame;
        result[1] = next_frame;
        return result;
    }
    return NULL;
}

const char* FrameTracker_analyze(FrameTracker *tracker, double *frame_pair) {
    if (frame_pair) {
        double current = frame_pair[0];
        double next_frame = frame_pair[1];
        double difference = fabs(next_frame - current);
        if (difference < tracker->precision) {
            return "Stable";
        } else {
            return "Changing";
        }
    }
    return "No Change";
}

void track_frames(double *sequence, int length) {
    FrameTracker *tracker = FrameTracker_init(sequence, length);
    while (1) {
        int frame_pair_length = 2;
        double *frame_pair = FrameTracker_update(tracker, &frame_pair_length);
        const char *status = FrameTracker_analyze(tracker, frame_pair);
        printf("%s\n", status);
        free(frame_pair);
    }
    FrameTracker_free(tracker);
}

int main() {
    double sequence[] = {0.0001, 0.00015, 0.0002, 0.00025, 0.0003};
    int length = sizeof(sequence) / sizeof(sequence[0]);
    track_frames(sequence, length);
    return 0;
}