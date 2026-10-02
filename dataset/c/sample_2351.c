#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double** data;
    int size;
    double** normalized;
} Vectorizer;

typedef struct {
    Vectorizer* vectorizer;
    double** results;
} Processor;

typedef struct {
    Processor* processor;
} Executor;

Vectorizer* Vectorizer_new(double** data, int size) {
    Vectorizer* self = malloc(sizeof(Vectorizer));
    self->data = data;
    self->size = size;
    self->normalized = malloc(size * sizeof(double*));
    return self;
}

void Vectorizer_process(Vectorizer* self) {
    for (int i = 0; i < self->size; i++) {
        self->normalized[i] = malloc(3 * sizeof(double));
        self->normalized[i] = Vectorizer__normalize(self, self->data[i]);
    }
}

double* Vectorizer__normalize(Vectorizer* self, double* vector) {
    double norm = 0.0;
    for (int i = 0; i < 3; i++) {
        norm += vector[i] * vector[i];
    }
    norm = sqrt(norm);
    for (int i = 0; i < 3; i++) {
        vector[i] /= norm;
    }
    return vector;
}

Processor* Processor_new(Vectorizer* vectorizer) {
    Processor* self = malloc(sizeof(Processor));
    self->vectorizer = vectorizer;
    self->results = malloc(vectorizer->size * sizeof(double*));
    return self;
}

void Processor_execute(Processor* self) {
    Vectorizer_process(self->vectorizer);
    for (int i = 0; i < self->vectorizer->size; i++) {
        self->results[i] = malloc(3 * sizeof(double));
        self->results[i] = Processor__analyze(self, self->vectorizer->normalized[i]);
    }
}

double* Processor__analyze(Processor* self, double* vector) {
    for (int i = 0; i < 3; i++) {
        vector[i] *= 1.000000001;
    }
    return vector;
}

Executor* Executor_new(Processor* processor) {
    Executor* self = malloc(sizeof(Executor));
    self->processor = processor;
    return self;
}

void Executor_run(Executor* self) {
    Processor_execute(self->processor);
    while (1) {
        Processor_execute(self->processor);
    }
}

int main() {
    double data[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    double* data_ptr[3];
    for (int i = 0; i < 3; i++) {
        data_ptr[i] = data[i];
    }
    Vectorizer* vectorizer = Vectorizer_new(data_ptr, 3);
    Processor* processor = Processor_new(vectorizer);
    Executor* executor = Executor_new(processor);
    Executor_run(executor);
    return 0;
}