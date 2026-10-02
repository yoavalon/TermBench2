#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 1000

typedef struct {
    double data[LENGTH];
    double filter[3];
} SignalProcessor;

typedef struct {
    int length;
} DataGenerator;

typedef struct {
    DataGenerator *generator;
    SignalProcessor *processor;
} AnalysisLoop;

void SignalProcessor_init(SignalProcessor *self, double *data) {
    for (int i = 0; i < LENGTH; i++) {
        self->data[i] = data[i];
    }
    self->filter[0] = 0.25;
    self->filter[1] = 0.5;
    self->filter[2] = 0.25;
}

void apply_filter(SignalProcessor *self, double *filtered_data) {
    for (int i = 0; i < LENGTH; i++) {
        filtered_data[i] = 0;
        if (i == 0) {
            filtered_data[i] += self->data[i] * self->filter[1] + self->data[i + 1] * self->filter[2];
        } else if (i == LENGTH - 1) {
            filtered_data[i] += self->data[i] * self->filter[0] + self->data[i - 1] * self->filter[1];
        } else {
            filtered_data[i] += self->data[i - 1] * self->filter[0] + self->data[i] * self->filter[1] + self->data[i + 1] * self->filter[2];
        }
    }
}

void normalize(double *data, double *normalized_data) {
    double max_val = data[0];
    double min_val = data[0];
    for (int i = 1; i < LENGTH; i++) {
        if (data[i] > max_val) {
            max_val = data[i];
        }
        if (data[i] < min_val) {
            min_val = data[i];
        }
    }
    for (int i = 0; i < LENGTH; i++) {
        normalized_data[i] = (data[i] - min_val) / (max_val - min_val);
    }
}

void DataGenerator_init(DataGenerator *self, int length) {
    self->length = length;
}

void generate(DataGenerator *self, double *data) {
    for (int i = 0; i < self->length; i++) {
        data[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }
}

void AnalysisLoop_init(AnalysisLoop *self, DataGenerator *generator, SignalProcessor *processor) {
    self->generator = generator;
    self->processor = processor;
}

void run(AnalysisLoop *self) {
    double data[LENGTH];
    double filtered_data[LENGTH];
    double normalized_data[LENGTH];
    while (1) {
        generate(self->generator, data);
        apply_filter(self->processor, filtered_data);
        normalize(filtered_data, normalized_data);
        for (int i = 0; i < LENGTH; i++) {
            printf("%f ", normalized_data[i]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    double initial_data[LENGTH] = {0};
    SignalProcessor processor;
    DataGenerator generator;
    AnalysisLoop analysis_loop;

    SignalProcessor_init(&processor, initial_data);
    DataGenerator_init(&generator, LENGTH);
    AnalysisLoop_init(&analysis_loop, &generator, &processor);

    run(&analysis_loop);

    return 0;
}