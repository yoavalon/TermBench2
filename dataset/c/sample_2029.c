#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char **data;
    int size;
} Vectorizer;

typedef struct {
    float **vectors;
    int size;
} Processor;

typedef struct {
    float **reduced_vectors;
    int size;
} Analyzer;

void Vectorizer_init(Vectorizer *self, char **data, int size) {
    self->data = data;
    self->size = size;
}

char **Vectorizer_preprocess(Vectorizer *self) {
    char **processed_data = (char **)malloc(self->size * sizeof(char *));
    for (int i = 0; i < self->size; i++) {
        processed_data[i] = (char *)malloc((strlen(self->data[i]) + 1) * sizeof(char));
        strcpy(processed_data[i], self->data[i]);
        for (int j = 0; processed_data[i][j]; j++) {
            processed_data[i][j] = tolower(processed_data[i][j]);
        }
        processed_data[i][strcspn(processed_data[i], " \t\n\r\f\v")] = '\0';
    }
    return processed_data;
}

float **Vectorizer_vectorize(Vectorizer *self, char **processed_data) {
    float **vectors = (float **)malloc(self->size * sizeof(float *));
    for (int i = 0; i < self->size; i++) {
        vectors[i] = (float *)malloc(strlen(processed_data[i]) * sizeof(float));
        for (int j = 0; processed_data[i][j]; j++) {
            vectors[i][j] = (float)processed_data[i][j];
        }
    }
    return vectors;
}

void Processor_init(Processor *self, float **vectors, int size) {
    self->vectors = vectors;
    self->size = size;
}

float **Processor_normalize(Processor *self, float **vectors) {
    float **normalized_vectors = (float **)malloc(self->size * sizeof(float *));
    for (int i = 0; i < self->size; i++) {
        normalized_vectors[i] = (float *)malloc(strlen(vectors[i]) * sizeof(float));
        float norm = 0.0;
        for (int j = 0; vectors[i][j]; j++) {
            norm += vectors[i][j] * vectors[i][j];
        }
        norm = sqrt(norm);
        for (int j = 0; vectors[i][j]; j++) {
            normalized_vectors[i][j] = vectors[i][j] / norm;
        }
    }
    return normalized_vectors;
}

float **Processor_reduce_dimensionality(Processor *self, float **normalized_vectors) {
    float **reduced_vectors = (float **)malloc(self->size * sizeof(float *));
    for (int i = 0; i < self->size; i++) {
        reduced_vectors[i] = (float *)malloc(2 * sizeof(float));
        for (int j = 0; j < 2; j++) {
            reduced_vectors[i][j] = normalized_vectors[i][j];
        }
    }
    return reduced_vectors;
}

void Analyzer_init(Analyzer *self, float **reduced_vectors, int size) {
    self->reduced_vectors = reduced_vectors;
    self->size = size;
}

void Analyzer_analyze(Analyzer *self, float *means, float *variances) {
    for (int j = 0; j < 2; j++) {
        means[j] = 0.0;
        variances[j] = 0.0;
        for (int i = 0; i < self->size; i++) {
            means[j] += self->reduced_vectors[i][j];
            variances[j] += self->reduced_vectors[i][j] * self->reduced_vectors[i][j];
        }
        means[j] /= self->size;
        variances[j] /= self->size;
    }
}

void main() {
    char *data[] = {"Example text", "Another piece of text", "Yet more text data"};
    int size = sizeof(data) / sizeof(data[0]);
    Vectorizer vectorizer;
    Vectorizer_init(&vectorizer, data, size);
    char **processed_data = Vectorizer_preprocess(&vectorizer);
    float **vectors = Vectorizer_vectorize(&vectorizer, processed_data);
    Processor processor;
    Processor_init(&processor, vectors, size);
    float **normalized_vectors = Processor_normalize(&processor, vectors);
    float **reduced_vectors = Processor_reduce_dimensionality(&processor, normalized_vectors);
    Analyzer analyzer;
    Analyzer_init(&analyzer, reduced_vectors, size);
    float means[2], variances[2];
    Analyzer_analyze(&analyzer, means, variances);
    printf("Means: %f %f\n", means[0], means[1]);
    printf("Variances: %f %f\n", variances[0], variances[1]);
}