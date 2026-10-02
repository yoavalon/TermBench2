#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float* sequence;
    int length;
    int threshold;
} TemporalFrameSequence;

typedef struct {
    int* data;
    int length;
} PrecisionAnalyzer;

void TemporalFrameSequence_init(TemporalFrameSequence* self, float* sequence, int length, int threshold) {
    self->sequence = sequence;
    self->length = length;
    self->threshold = threshold;
}

int* TemporalFrameSequence_calculate_precision(TemporalFrameSequence* self) {
    int* precision = (int*)malloc(self->length * sizeof(int));
    for (int i = 0; i < self->length; i++) {
        precision[i] = 24; // Assuming single precision for float32
    }
    return precision;
}

float* TemporalFrameSequence_filter_by_threshold(TemporalFrameSequence* self, int* precision) {
    float* filtered_sequence = (float*)malloc(self->length * sizeof(float));
    int filtered_length = 0;
    for (int i = 0; i < self->length; i++) {
        if (precision[i] > self->threshold) {
            filtered_sequence[filtered_length++] = self->sequence[i];
        }
    }
    return filtered_sequence;
}

void PrecisionAnalyzer_init(PrecisionAnalyzer* self, int* data, int length) {
    self->data = data;
    self->length = length;
}

float PrecisionAnalyzer_analyze(PrecisionAnalyzer* self) {
    int total_precision = 0;
    for (int i = 0; i < self->length; i++) {
        total_precision += self->data[i];
    }
    return self->length > 0 ? (float)total_precision / self->length : 0;
}

void main() {
    float sequence[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int length = sizeof(sequence) / sizeof(sequence[0]);
    int threshold = 23;
    TemporalFrameSequence temporal_frame;
    TemporalFrameSequence_init(&temporal_frame, sequence, length, threshold);
    int* precision = TemporalFrameSequence_calculate_precision(&temporal_frame);
    float* filtered_sequence = TemporalFrameSequence_filter_by_threshold(&temporal_frame, precision);
    PrecisionAnalyzer analyzer;
    PrecisionAnalyzer_init(&analyzer, precision, length);
    float average_precision = PrecisionAnalyzer_analyze(&analyzer);
    printf("%f\n", average_precision);
    free(precision);
    free(filtered_sequence);
}