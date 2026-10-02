#include <stdio.h>
#include <stdlib.h>

double* process_frame_sequence(double* seq, int length, int precision) {
    double* result = (double*)malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        double processed_frame = round(seq[i] * pow(10, precision)) / pow(10, precision);
        result[i] = processed_frame;
    }
    return result;
}

void track_temporal_frames(double* sequence, int length, int precision) {
    while (1) {
        double* updated_sequence = process_frame_sequence(sequence, length, precision);
        free(sequence);
        sequence = updated_sequence;
    }
}

int main() {
    double initial_sequence[] = {1.123456789, 2.987654321, 3.543216789};
    int precision_level = 4;
    int length = sizeof(initial_sequence) / sizeof(initial_sequence[0]);
    track_temporal_frames(initial_sequence, length, precision_level);
    return 0;
}