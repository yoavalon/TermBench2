#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 3
#define MAX_WORD_LENGTH 50

typedef struct {
    double tfidf[MAX_DATA][MAX_WORD_LENGTH];
} TfidfVectorizer;

TfidfVectorizer* TfidfVectorizer_init() {
    TfidfVectorizer* vectorizer = (TfidfVectorizer*)malloc(sizeof(TfidfVectorizer));
    return vectorizer;
}

void TfidfVectorizer_fit_transform(TfidfVectorizer* vectorizer, char* data[], int n) {
    // Placeholder for actual TF-IDF computation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAX_WORD_LENGTH; j++) {
            vectorizer->tfidf[i][j] = 0.0; // Simplified representation
        }
    }
}

double** TfidfVectorizer_toarray(TfidfVectorizer* vectorizer) {
    double** array = (double**)malloc(MAX_DATA * sizeof(double*));
    for (int i = 0; i < MAX_DATA; i++) {
        array[i] = (double*)malloc(MAX_WORD_LENGTH * sizeof(double));
        for (int j = 0; j < MAX_WORD_LENGTH; j++) {
            array[i][j] = vectorizer->tfidf[i][j];
        }
    }
    return array;
}

void free_TfidfVectorizer(TfidfVectorizer* vectorizer) {
    free(vectorizer);
}

void analyze_vectors(double** vectors, int n, double* mean, double* variance) {
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        mean[i] = 0.0;
        variance[i] = 0.0;
        for (int j = 0; j < n; j++) {
            mean[i] += vectors[j][i];
            variance[i] += vectors[j][i] * vectors[j][i];
        }
        mean[i] /= n;
        variance[i] /= n;
    }
}

int main() {
    char* data[MAX_DATA] = {"hello world", "data science", "machine learning"};
    TfidfVectorizer* vectorizer = TfidfVectorizer_init();
    TfidfVectorizer_fit_transform(vectorizer, data, MAX_DATA);
    double** vectors = TfidfVectorizer_toarray(vectorizer);
    double mean[MAX_WORD_LENGTH];
    double variance[MAX_WORD_LENGTH];
    analyze_vectors(vectors, MAX_DATA, mean, variance);
    printf("Mean Vector: ");
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        printf("%f ", mean[i]);
    }
    printf("\nVariance Vector: ");
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        printf("%f ", variance[i]);
    }
    printf("\n");
    free_TfidfVectorizer(vectorizer);
    for (int i = 0; i < MAX_DATA; i++) {
        free(vectors[i]);
    }
    free(vectors);
    return 0;
}