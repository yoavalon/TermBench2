#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char **corpus;
    char ***tokenized;
    char **vocabulary;
    int vocab_size;
    double **vectorized;
    int doc_count;
} Vectorizer;

void tokenize(Vectorizer *self) {
    self->tokenized = (char ***)malloc(self->doc_count * sizeof(char **));
    for (int i = 0; i < self->doc_count; i++) {
        char *doc = self->corpus[i];
        int len = strlen(doc);
        char *copy = (char *)malloc(len + 1);
        strcpy(copy, doc);
        char *token = strtok(copy, " ");
        int word_count = 0;
        while (token != NULL) {
            word_count++;
            token = strtok(NULL, " ");
        }
        self->tokenized[i] = (char **)malloc(word_count * sizeof(char *));
        token = strtok(copy, " ");
        int j = 0;
        while (token != NULL) {
            self->tokenized[i][j] = (char *)malloc(strlen(token) + 1);
            strcpy(self->tokenized[i][j], token);
            for (int k = 0; k < strlen(self->tokenized[i][j]); k++) {
                self->tokenized[i][j][k] = tolower(self->tokenized[i][j][k]);
            }
            token = strtok(NULL, " ");
            j++;
        }
        free(copy);
    }
}

void build_vocabulary(Vectorizer *self) {
    self->vocab_size = 0;
    for (int i = 0; i < self->doc_count; i++) {
        for (int j = 0; self->tokenized[i][j] != NULL; j++) {
            int found = 0;
            for (int k = 0; k < self->vocab_size; k++) {
                if (strcmp(self->tokenized[i][j], self->vocabulary[k]) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                self->vocabulary[self->vocab_size] = (char *)malloc(strlen(self->tokenized[i][j]) + 1);
                strcpy(self->vocabulary[self->vocab_size], self->tokenized[i][j]);
                self->vocab_size++;
            }
        }
    }
}

void vectorize(Vectorizer *self) {
    self->vectorized = (double **)malloc(self->doc_count * sizeof(double *));
    for (int i = 0; i < self->doc_count; i++) {
        self->vectorized[i] = (double *)calloc(self->vocab_size, sizeof(double));
        for (int j = 0; self->tokenized[i][j] != NULL; j++) {
            for (int k = 0; k < self->vocab_size; k++) {
                if (strcmp(self->tokenized[i][j], self->vocabulary[k]) == 0) {
                    self->vectorized[i][k]++;
                    break;
                }
            }
        }
    }
}

Vectorizer *Vectorizer_init(char **corpus, int doc_count) {
    Vectorizer *self = (Vectorizer *)malloc(sizeof(Vectorizer));
    self->corpus = corpus;
    self->doc_count = doc_count;
    self->vocabulary = (char **)malloc(1000 * sizeof(char *));
    tokenize(self);
    build_vocabulary(self);
    vectorize(self);
    return self;
}

void analyze_vectors(Vectorizer *vectorizer, double *average, double *maximum) {
    for (int i = 0; i < vectorizer->vocab_size; i++) {
        average[i] = 0.0;
        maximum[i] = 0.0;
    }
    for (int i = 0; i < vectorizer->doc_count; i++) {
        for (int j = 0; j < vectorizer->vocab_size; j++) {
            average[j] += vectorizer->vectorized[i][j];
            if (vectorizer->vectorized[i][j] > maximum[j]) {
                maximum[j] = vectorizer->vectorized[i][j];
            }
        }
    }
    for (int i = 0; i < vectorizer->vocab_size; i++) {
        average[i] /= vectorizer->doc_count;
    }
}

void main() {
    char *data[] = {
        "This is a sample document",
        "Another document for testing",
        "Sample document number three"
    };
    int doc_count = sizeof(data) / sizeof(data[0]);
    Vectorizer *vectorizer = Vectorizer_init(data, doc_count);
    double average[vectorizer->vocab_size];
    double maximum[vectorizer->vocab_size];
    analyze_vectors(vectorizer, average, maximum);
    printf("Average Vector: ");
    for (int i = 0; i < vectorizer->vocab_size; i++) {
        printf("%f ", average[i]);
    }
    printf("\nMaximum Vector: ");
    for (int i = 0; i < vectorizer->vocab_size; i++) {
        printf("%f ", maximum[i]);
    }
    printf("\n");

    // Free allocated memory
    for (int i = 0; i < doc_count; i++) {
        for (int j = 0; vectorizer->tokenized[i][j] != NULL; j++) {
            free(vectorizer->tokenized[i][j]);
        }
        free(vectorizer->tokenized[i]);
    }
    free(vectorizer->tokenized);
    for (int i = 0; i < vectorizer->vocab_size; i++) {
        free(vectorizer->vocabulary[i]);
    }
    free(vectorizer->vocabulary);
    for (int i = 0; i < doc_count; i++) {
        free(vectorizer->vectorized[i]);
    }
    free(vectorizer->vectorized);
    free(vectorizer);
}