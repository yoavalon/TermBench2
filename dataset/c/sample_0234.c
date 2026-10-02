#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double *signal;
    int signal_length;
    double threshold;
} BoundaryProcessor;

typedef struct {
    BoundaryProcessor *processor;
} SignalAnalyzer;

void BoundaryProcessor_init(BoundaryProcessor *self, double *signal, int signal_length, double threshold) {
    self->signal = signal;
    self->signal_length = signal_length;
    self->threshold = threshold;
}

int* BoundaryProcessor_apply_threshold(BoundaryProcessor *self, int *processed_signal_length) {
    int *processed_signal = (int*)malloc(self->signal_length * sizeof(int));
    for (int i = 0; i < self->signal_length; i++) {
        if (self->signal[i] > self->threshold) {
            processed_signal[i] = 1;
        } else {
            processed_signal[i] = 0;
        }
    }
    *processed_signal_length = self->signal_length;
    return processed_signal;
}

int* BoundaryProcessor_detect_edges(BoundaryProcessor *self, int *processed_signal, int processed_signal_length, int *edges_length) {
    int *edges = (int*)malloc((processed_signal_length - 1) * sizeof(int));
    int count = 0;
    for (int i = 1; i < processed_signal_length; i++) {
        if (processed_signal[i] != processed_signal[i - 1]) {
            edges[count++] = i;
        }
    }
    *edges_length = count;
    return edges;
}

void SignalAnalyzer_init(SignalAnalyzer *self, BoundaryProcessor *processor) {
    self->processor = processor;
}

int* SignalAnalyzer_analyze(SignalAnalyzer *self, int *edges_length) {
    int processed_signal_length;
    int *processed_signal = BoundaryProcessor_apply_threshold(self->processor, &processed_signal_length);
    int *edges = BoundaryProcessor_detect_edges(self->processor, processed_signal, processed_signal_length, edges_length);
    free(processed_signal);
    return edges;
}

void main() {
    double signal[] = {0.1, 0.3, 0.5, 0.8, 0.4, 0.9, 0.2, 0.7};
    int signal_length = sizeof(signal) / sizeof(signal[0]);
    double threshold = 0.5;
    BoundaryProcessor processor;
    BoundaryProcessor_init(&processor, signal, signal_length, threshold);
    SignalAnalyzer analyzer;
    SignalAnalyzer_init(&analyzer, &processor);
    int edges_length;
    int *result = SignalAnalyzer_analyze(&analyzer, &edges_length);
    for (int i = 0; i < edges_length; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
}