#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    int dimension;
} Vectorizer;

void Vectorizer_init(Vectorizer* self, int dimension) {
    self->dimension = dimension;
}

double* Vectorizer_create_random_vector(Vectorizer* self) {
    double* vector = (double*)malloc(self->dimension * sizeof(double));
    for (int i = 0; i < self->dimension; i++) {
        vector[i] = (double)rand() / RAND_MAX;
    }
    return vector;
}

double* Vectorizer_normalize_vector(Vectorizer* self, double* vector) {
    double norm = 0.0;
    for (int i = 0; i < self->dimension; i++) {
        norm += vector[i] * vector[i];
    }
    norm = sqrt(norm);
    if (norm == 0.0) {
        return vector;
    }
    for (int i = 0; i < self->dimension; i++) {
        vector[i] /= norm;
    }
    return vector;
}

typedef struct {
    Vectorizer* vectorizer;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator* self, Vectorizer* vectorizer) {
    self->vectorizer = vectorizer;
}

double** SequenceGenerator_generate_sequence(SequenceGenerator* self, int length) {
    double** sequence = (double**)malloc(length * sizeof(double*));
    for (int i = 0; i < length; i++) {
        double* vector = self->vectorizer->create_random_vector(self->vectorizer);
        double* normalized_vector = self->vectorizer->normalize_vector(self->vectorizer, vector);
        sequence[i] = normalized_vector;
    }
    return sequence;
}

typedef struct {
    SequenceGenerator* sequence_generator;
} Processor;

void Processor_init(Processor* self, SequenceGenerator* sequence_generator) {
    self->sequence_generator = sequence_generator;
}

double** Processor_process_sequence(Processor* self, double** sequence, int length) {
    double** processed_sequence = (double**)malloc(length * sizeof(double*));
    for (int i = 0; i < length; i++) {
        double* vector = sequence[i];
        double* processed_vector = (double*)malloc(self->sequence_generator->vectorizer->dimension * sizeof(double));
        for (int j = 0; j < self->sequence_generator->vectorizer->dimension; j++) {
            processed_vector[j] = sin(vector[j]);
        }
        processed_sequence[i] = processed_vector;
    }
    return processed_sequence;
}

int main() {
    srand(time(NULL));
    int dimension = 10;
    int length = 1000;
    Vectorizer vectorizer;
    Vectorizer_init(&vectorizer, dimension);
    SequenceGenerator sequence_generator;
    SequenceGenerator_init(&sequence_generator, &vectorizer);
    Processor processor;
    Processor_init(&processor, &sequence_generator);
    while (1) {
        double** sequence = SequenceGenerator_generate_sequence(&sequence_generator, length);
        double** processed_sequence = Processor_process_sequence(&processor, sequence, length);
    }
    return 0;
}