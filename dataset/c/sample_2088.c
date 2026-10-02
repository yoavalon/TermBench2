#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float *elements;
    int length;
} Vector;

void Vector_init(Vector *self, float *elements, int length) {
    self->elements = elements;
    self->length = length;
}

float Vector_magnitude(Vector *self) {
    float sum = 0;
    for (int i = 0; i < self->length; i++) {
        sum += pow(self->elements[i], 2);
    }
    return sqrt(sum);
}

void Vector_normalize(Vector *self) {
    float mag = Vector_magnitude(self);
    for (int i = 0; i < self->length; i++) {
        self->elements[i] /= mag;
    }
}

float cosine_similarity(Vector *vec1, Vector *vec2) {
    if (vec1->length != vec2->length) {
        fprintf(stderr, "Vectors must be of the same length\n");
        exit(EXIT_FAILURE);
    }
    float dot_product = 0;
    for (int i = 0; i < vec1->length; i++) {
        dot_product += vec1->elements[i] * vec2->elements[i];
    }
    return dot_product / (Vector_magnitude(vec1) * Vector_magnitude(vec2));
}

typedef struct {
    int idx1;
    int idx2;
    float similarity;
} SimilarityResult;

SimilarityResult *process_vectors(float **data, int num_vectors, int vector_length) {
    Vector *vectors = malloc(num_vectors * sizeof(Vector));
    for (int i = 0; i < num_vectors; i++) {
        Vector_init(&vectors[i], data[i], vector_length);
    }

    SimilarityResult *results = malloc((num_vectors * (num_vectors - 1) / 2) * sizeof(SimilarityResult));
    int result_index = 0;
    for (int i = 0; i < num_vectors; i++) {
        for (int j = i + 1; j < num_vectors; j++) {
            Vector_normalize(&vectors[i]);
            Vector_normalize(&vectors[j]);
            float similarity = cosine_similarity(&vectors[i], &vectors[j]);
            results[result_index].idx1 = i;
            results[result_index].idx2 = j;
            results[result_index].similarity = similarity;
            result_index++;
        }
    }
    free(vectors);
    return results;
}

int main() {
    float data[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    SimilarityResult *similarities = process_vectors((float **)data, 3, 3);
    for (int i = 0; i < 3; i++) {
        printf("Similarity between vector %d and %d: %.4f\n", similarities[i].idx1, similarities[i].idx2, similarities[i].similarity);
    }
    free(similarities);
    return 0;
}