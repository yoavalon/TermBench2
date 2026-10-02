#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    double* sequence;
    int length;
} SequenceProcessor;

SequenceProcessor* SequenceProcessor_init(double* sequence, int length) {
    SequenceProcessor* processor = (SequenceProcessor*)malloc(sizeof(SequenceProcessor));
    processor->sequence = sequence;
    processor->length = length;
    return processor;
}

void SequenceProcessor_free(SequenceProcessor* processor) {
    free(processor->sequence);
    free(processor);
}

double* SequenceProcessor_transform_sequence(SequenceProcessor* processor) {
    double* transformed = (double*)malloc(processor->length * sizeof(double));
    for (int i = 0; i < processor->length; i++) {
        double value = processor->sequence[i];
        transformed[i] = sin(value) * cos(value);
    }
    return transformed;
}

double* SequenceProcessor_analyze(SequenceProcessor* processor, double* sequence) {
    double* analysis = (double*)malloc(processor->length * sizeof(double));
    for (int i = 0; i < processor->length; i++) {
        analysis[i] = round(sequence[i] * 10000) / 10000;
    }
    return analysis;
}

double* generate_sequence(int n) {
    double* sequence = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        sequence[i] = sqrt(i + 1);
    }
    return sequence;
}

void main() {
    int n = 10;
    double* sequence = generate_sequence(n);
    SequenceProcessor* processor = SequenceProcessor_init(sequence, n);
    double* transformed = SequenceProcessor_transform_sequence(processor);
    double* result = SequenceProcessor_analyze(processor, transformed);

    for (int i = 0; i < n; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");

    SequenceProcessor_free(processor);
    free(transformed);
    free(result);
}