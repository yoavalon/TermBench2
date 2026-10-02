#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SAMPLES 100
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    int count[MAX_WORDS];
    int size;
} CountMatrix;

void preprocess_data(const char* data[], int num_samples, CountMatrix* matrix) {
    matrix->size = 0;
    memset(matrix->count, 0, sizeof(matrix->count));

    for (int i = 0; i < num_samples; i++) {
        const char* token = strtok((char*)data[i], " ");
        while (token != NULL) {
            if (strlen(token) > 1) {
                int index = 0;
                for (int j = 0; token[j] != '\0'; j++) {
                    token[j] = tolower(token[j]);
                    index = (index * 257 + token[j]) % MAX_WORDS;
                }
                matrix->count[index]++;
            }
            token = strtok(NULL, " ");
        }
    }
}

void mutate_vectors(CountMatrix* matrix) {
    for (int i = 0; i < matrix->size; i++) {
        if (matrix->count[i] > 0) {
            matrix->count[i] = rand() % 9 + 1;
        }
    }
}

int main() {
    srand(time(NULL));

    const char* data_samples[] = {
        "The quick brown fox jumps over the lazy dog",
        "Hello world! This is a test sentence.",
        "Another example with some words."
    };
    int num_samples = sizeof(data_samples) / sizeof(data_samples[0]);

    CountMatrix matrix;
    preprocess_data(data_samples, num_samples, &matrix);

    mutate_vectors(&matrix);

    for (int i = 0; i < matrix.size; i++) {
        if (matrix.count[i] > 0) {
            printf("%d ", matrix.count[i]);
        }
    }
    printf("\n");

    return 0;
}