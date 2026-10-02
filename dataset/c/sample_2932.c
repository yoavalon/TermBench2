#include <stdio.h>
#include <math.h>

typedef struct {
    double* sequence;
    int sequence_length;
    double* vector;
    int vector_length;
} Vectorizer;

typedef struct {
    int index;
} SequenceGenerator;

typedef struct {
    SequenceGenerator generator;
} Processor;

void vectorizer_init(Vectorizer* self, double* sequence, int length) {
    self->sequence = sequence;
    self->sequence_length = length;
    self->vector = NULL;
    self->vector_length = 0;
}

void vectorizer_vectorize(Vectorizer* self) {
    self->vector = (double*)malloc(self->sequence_length * sizeof(double));
    for (int i = 0; i < self->sequence_length; i++) {
        self->vector[i] = sin(self->sequence[i]);
    }
    self->vector_length = self->sequence_length;
}

void vectorizer_normalize(Vectorizer* self) {
    double total = 0;
    for (int i = 0; i < self->vector_length; i++) {
        total += self->vector[i];
    }
    for (int i = 0; i < self->vector_length; i++) {
        self->vector[i] /= total;
    }
}

void vectorizer_process(Vectorizer* self) {
    vectorizer_vectorize(self);
    vectorizer_normalize(self);
}

void sequence_generator_init(SequenceGenerator* self) {
    self->index = 0;
}

double sequence_generator_next(SequenceGenerator* self) {
    self->index++;
    return sqrt(self->index);
}

void processor_init(Processor* self) {
    sequence_generator_init(&self->generator);
}

void processor_run(Processor* self) {
    while (1) {
        double sequence[100];
        for (int i = 0; i < 100; i++) {
            sequence[i] = sequence_generator_next(&self->generator);
        }
        Vectorizer vectorizer;
        vectorizer_init(&vectorizer, sequence, 100);
        vectorizer_process(&vectorizer);
        for (int i = 0; i < vectorizer.vector_length; i++) {
            printf("%f ", vectorizer.vector[i]);
        }
        printf("\n");
        free(vectorizer.vector);
    }
}

int main() {
    Processor processor;
    processor_init(&processor);
    processor_run(&processor);
    return 0;
}