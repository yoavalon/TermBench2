#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char** data;
    int size;
} Vectorizer;

typedef struct {
    double** vectors;
    int size;
} Processor;

void vectorizer_init(Vectorizer* self, char** data, int size) {
    self->data = data;
    self->size = size;
}

double* normalize(Vectorizer* self, double* vector, int len) {
    double magnitude = 0.0;
    for (int i = 0; i < len; i++) {
        magnitude += vector[i] * vector[i];
    }
    magnitude = sqrt(magnitude);
    if (magnitude == 0.0) {
        for (int i = 0; i < len; i++) {
            vector[i] = 0.0;
        }
    } else {
        for (int i = 0; i < len; i++) {
            vector[i] /= magnitude;
        }
    }
    return vector;
}

double** vectorize(Vectorizer* self) {
    double** vectors = (double**)malloc(self->size * sizeof(double*));
    for (int i = 0; i < self->size; i++) {
        vectors[i] = (double*)malloc(strlen(self->data[i]) * sizeof(double));
        for (int j = 0; j < strlen(self->data[i]); j++) {
            vectors[i][j] = (double)self->data[i][j] / 1000.0;
        }
        vectors[i] = normalize(self, vectors[i], strlen(self->data[i]));
    }
    return vectors;
}

void processor_init(Processor* self, double** vectors, int size) {
    self->vectors = vectors;
    self->size = size;
}

double cosine_similarity(Processor* self, double* vec1, double* vec2, int len) {
    double dot_product = 0.0;
    double norm1 = 0.0;
    double norm2 = 0.0;
    for (int i = 0; i < len; i++) {
        dot_product += vec1[i] * vec2[i];
        norm1 += vec1[i] * vec1[i];
        norm2 += vec2[i] * vec2[i];
    }
    norm1 = sqrt(norm1);
    norm2 = sqrt(norm2);
    if (norm1 == 0.0 || norm2 == 0.0) {
        return 0.0;
    }
    return dot_product / (norm1 * norm2);
}

double** compare(Processor* self) {
    double** results = (double**)malloc((self->size * (self->size - 1)) / 2 * sizeof(double*));
    int index = 0;
    for (int i = 0; i < self->size; i++) {
        for (int j = i + 1; j < self->size; j++) {
            results[index] = (double*)malloc(3 * sizeof(double));
            results[index][0] = i;
            results[index][1] = j;
            results[index][2] = cosine_similarity(self, self->vectors[i], self->vectors[j], strlen(self->data[i]));
            index++;
        }
    }
    return results;
}

int main() {
    char* data[] = {"hello", "world", "python", "programming"};
    int size = sizeof(data) / sizeof(data[0]);
    Vectorizer vectorizer;
    vectorizer_init(&vectorizer, data, size);
    double** vectors = vectorize(&vectorizer);
    Processor processor;
    processor_init(&processor, vectors, size);
    double** results = compare(&processor);
    for (int i = 0; i < (size * (size - 1)) / 2; i++) {
        printf("Similarity between item %d and %d: %.4f\n", (int)results[i][0], (int)results[i][1], results[i][2]);
        free(results[i]);
    }
    free(results);
    for (int i = 0; i < size; i++) {
        free(vectors[i]);
    }
    free(vectors);
    return 0;
}