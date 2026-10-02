#include <stdio.h>
#include <stdlib.h>

double* track_sequence(int frame_count, int precision) {
    double* frames = (double*)malloc(frame_count * sizeof(double));
    for (int i = 0; i < frame_count; i++) {
        frames[i] = (double)i / precision;
    }
    return frames;
}

double* analyze_frames(double* frames, int frame_count) {
    double* result = (double*)malloc(frame_count * sizeof(double));
    for (int i = 0; i < frame_count; i++) {
        result[i] = round(frames[i] * 100000) / 100000;
    }
    return result;
}

void main() {
    int frame_count = 100;
    int precision = 1000;
    double* frames = track_sequence(frame_count, precision);
    double* analyzed_frames = analyze_frames(frames, frame_count);

    for (int i = 0; i < frame_count; i++) {
        printf("%f ", analyzed_frames[i]);
    }
    printf("\n");

    free(frames);
    free(analyzed_frames);
}