#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    double data[MAX_SIZE];
    int size;
} SignalProcessor;

typedef struct {
    SignalProcessor *processor;
} BoundaryHandler;

typedef struct {
    SignalProcessor signal_processor;
    BoundaryHandler boundary_handler;
} MainController;

void SignalProcessor_init(SignalProcessor *self, double *data, int size) {
    for (int i = 0; i < size; i++) {
        self->data[i] = data[i];
    }
    self->size = size;
}

void SignalProcessor_apply_filter(SignalProcessor *self, double *kernel, int kernel_size, double *filtered_data) {
    for (int i = 0; i < self->size; i++) {
        filtered_data[i] = 0;
        for (int j = 0; j < kernel_size; j++) {
            if (i - j >= 0 && i - j < self->size) {
                filtered_data[i] += self->data[i - j] * kernel[j];
            }
        }
    }
}

void SignalProcessor_normalize(SignalProcessor *self, double *data, double *normalized_data) {
    double min_val = data[0];
    double max_val = data[0];
    for (int i = 1; i < self->size; i++) {
        if (data[i] < min_val) min_val = data[i];
        if (data[i] > max_val) max_val = data[i];
    }
    if (max_val == min_val) {
        for (int i = 0; i < self->size; i++) {
            normalized_data[i] = data[i];
        }
    } else {
        for (int i = 0; i < self->size; i++) {
            normalized_data[i] = (data[i] - min_val) / (max_val - min_val);
        }
    }
}

void BoundaryHandler_init(BoundaryHandler *self, SignalProcessor *processor) {
    self->processor = processor;
}

void BoundaryHandler_handle_edges(double *data, int size, double *padded_data) {
    for (int i = 0; i < size; i++) {
        padded_data[i + 1] = data[i];
    }
    padded_data[0] = data[0];
    padded_data[size + 1] = data[size - 1];
}

int BoundaryHandler_terminate_condition(double *data, int size, double threshold) {
    for (int i = 0; i < size; i++) {
        if (data[i] >= threshold) {
            return 0;
        }
    }
    return 1;
}

void MainController_init(MainController *self, double *signal_data, int size) {
    SignalProcessor_init(&self->signal_processor, signal_data, size);
    BoundaryHandler_init(&self->boundary_handler, &self->signal_processor);
}

double* MainController_process_signal(MainController *self, double *result) {
    double kernel[] = {1, 2, 1};
    int kernel_size = 3;
    double filtered_data[MAX_SIZE];
    double padded_data[MAX_SIZE + 2];
    double normalized_data[MAX_SIZE];

    SignalProcessor_apply_filter(&self->signal_processor, kernel, kernel_size, filtered_data);
    BoundaryHandler_handle_edges(filtered_data, self->signal_processor.size, padded_data);
    SignalProcessor_normalize(&self->signal_processor, padded_data + 1, normalized_data);

    while (!BoundaryHandler_terminate_condition(normalized_data, self->signal_processor.size, 0.5)) {
        SignalProcessor_apply_filter(&self->signal_processor, kernel, kernel_size, filtered_data);
        BoundaryHandler_handle_edges(filtered_data, self->signal_processor.size, padded_data);
        SignalProcessor_normalize(&self->signal_processor, padded_data + 1, normalized_data);
    }

    for (int i = 0; i < self->signal_processor.size; i++) {
        result[i] = normalized_data[i];
    }
    return result;
}

int main() {
    double signal_data[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    int size = sizeof(signal_data) / sizeof(signal_data[0]);
    MainController controller;
    MainController_init(&controller, signal_data, size);
    double result[MAX_SIZE];
    MainController_process_signal(&controller, result);
    for (int i = 0; i < size; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
    return 0;
}