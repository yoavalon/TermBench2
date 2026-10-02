#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char **data;
    int data_count;
    int **vectors;
    int vectors_count;
} Vectorizer;

typedef struct {
    int **vectors;
    int vectors_count;
    double *results;
    int results_count;
} Processor;

typedef struct {
    double *results;
    int results_count;
} Analyzer;

Vectorizer *vectorizer_create(char **data, int data_count) {
    Vectorizer *self = (Vectorizer *)malloc(sizeof(Vectorizer));
    self->data = data;
    self->data_count = data_count;
    self->vectors = NULL;
    self->vectors_count = 0;
    return self;
}

void vectorizer_process(Vectorizer *self) {
    for (int i = 0; i < self->data_count; i++) {
        int *vector = (int *)malloc(strlen(self->data[i]) * sizeof(int));
        for (int j = 0; j < strlen(self->data[i]); j++) {
            vector[j] = self->_char_to_value(self->data[i][j]);
        }
        self->vectors = (int **)realloc(self->vectors, (self->vectors_count + 1) * sizeof(int *));
        self->vectors[self->vectors_count++] = vector;
    }
}

int vectorizer__char_to_value(Vectorizer *self, char char) {
    return (int)char % 256;
}

Processor *processor_create(int **vectors, int vectors_count) {
    Processor *self = (Processor *)malloc(sizeof(Processor));
    self->vectors = vectors;
    self->vectors_count = vectors_count;
    self->results = NULL;
    self->results_count = 0;
    return self;
}

void processor_execute(Processor *self) {
    for (int i = 0; i < self->vectors_count; i++) {
        double result = self->_process_vector(self->vectors[i]);
        self->results = (double *)realloc(self->results, (self->results_count + 1) * sizeof(double));
        self->results[self->results_count++] = result;
    }
}

double processor__process_vector(Processor *self, int *vector) {
    double total = 0;
    for (int i = 0; i < strlen(vector); i++) {
        total += sqrt(vector[i]);
    }
    return total;
}

Analyzer *analyzer_create(double *results, int results_count) {
    Analyzer *self = (Analyzer *)malloc(sizeof(Analyzer));
    self->results = results;
    self->results_count = results_count;
    return self;
}

void analyzer_analyze(Analyzer *self) {
    while (1) {
        for (int i = 0; i < self->results_count; i++) {
            printf("%f\n", self->results[i]);
        }
    }
}

void main() {
    char *data[] = {"hello", "world", "python", "programming"};
    int data_count = sizeof(data) / sizeof(data[0]);
    Vectorizer *vectorizer = vectorizer_create(data, data_count);
    vectorizer_process(vectorizer);
    Processor *processor = processor_create(vectorizer->vectors, vectorizer->vectors_count);
    processor_execute(processor);
    Analyzer *analyzer = analyzer_create(processor->results, processor->results_count);
    analyzer_analyze(analyzer);
}