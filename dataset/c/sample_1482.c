#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DOCUMENTS 5
#define MAX_WORDS 100
#define WORD_LENGTH 50

typedef struct {
    char data[MAX_DOCUMENTS][WORD_LENGTH];
} Vectorizer;

void vectorizer_init(Vectorizer *self, char data[][WORD_LENGTH]) {
    for (int i = 0; i < MAX_DOCUMENTS; i++) {
        strcpy(self->data[i], data[i]);
    }
}

void vectorizer_fit_transform(Vectorizer *self, int vectors[MAX_DOCUMENTS][MAX_WORDS]) {
    // Simulate CountVectorizer.fit_transform
    for (int i = 0; i < MAX_DOCUMENTS; i++) {
        char *token = strtok(self->data[i], " ");
        int j = 0;
        while (token != NULL) {
            vectors[i][j++] = 1; // Simplified token count
            token = strtok(NULL, " ");
        }
    }
}

typedef struct {
    int vectors[MAX_DOCUMENTS][MAX_WORDS];
} Processor;

void processor_init(Processor *self, int vectors[MAX_DOCUMENTS][MAX_WORDS]) {
    for (int i = 0; i < MAX_DOCUMENTS; i++) {
        for (int j = 0; j < MAX_WORDS; j++) {
            self->vectors[i][j] = vectors[i][j];
        }
    }
}

void processor_normalize(Processor *self) {
    for (int i = 0; i < MAX_DOCUMENTS; i++) {
        double norm = 0;
        for (int j = 0; j < MAX_WORDS; j++) {
            norm += self->vectors[i][j] * self->vectors[i][j];
        }
        norm = sqrt(norm);
        if (norm == 0) {
            norm = 1;
        }
        for (int j = 0; j < MAX_WORDS; j++) {
            self->vectors[i][j] /= norm;
        }
    }
}

void processor_filter(Processor *self, int threshold, int filtered_vectors[MAX_DOCUMENTS][MAX_WORDS], int *filtered_count) {
    *filtered_count = 0;
    for (int i = 0; i < MAX_DOCUMENTS; i++) {
        int sum = 0;
        for (int j = 0; j < MAX_WORDS; j++) {
            sum += self->vectors[i][j] > threshold;
        }
        if (sum > 0) {
            for (int j = 0; j < MAX_WORDS; j++) {
                filtered_vectors[*filtered_count][j] = self->vectors[i][j];
            }
            (*filtered_count)++;
        }
    }
}

typedef struct {
    int data[MAX_DOCUMENTS][MAX_WORDS];
} Analysis;

void analysis_init(Analysis *self, int data[MAX_DOCUMENTS][MAX_WORDS]) {
    for (int i = 0; i < MAX_DOCUMENTS; i++) {
        for (int j = 0; j < MAX_WORDS; j++) {
            self->data[i][j] = data[i][j];
        }
    }
}

void analysis_analyze(Analysis *self, double mean_vector[MAX_WORDS], double variance_vector[MAX_WORDS]) {
    for (int j = 0; j < MAX_WORDS; j++) {
        mean_vector[j] = 0;
        variance_vector[j] = 0;
        for (int i = 0; i < MAX_DOCUMENTS; i++) {
            mean_vector[j] += self->data[i][j];
            variance_vector[j] += self->data[i][j] * self->data[i][j];
        }
        mean_vector[j] /= MAX_DOCUMENTS;
        variance_vector[j] /= MAX_DOCUMENTS;
        variance_vector[j] -= mean_vector[j] * mean_vector[j];
    }
}

void main() {
    char data[MAX_DOCUMENTS][WORD_LENGTH] = {
        "Natural language processing is fascinating.",
        "Vectorization is a key technique in NLP.",
        "Machine learning models learn from data.",
        "Data preprocessing is crucial for NLP tasks.",
        "Understanding human language is complex."
    };
    Vectorizer vectorizer;
    vectorizer_init(&vectorizer, data);
    int vectors[MAX_DOCUMENTS][MAX_WORDS];
    vectorizer_fit_transform(&vectorizer, vectors);
    Processor processor;
    processor_init(&processor, vectors);
    processor_normalize(&processor);
    int filtered_vectors[MAX_DOCUMENTS][MAX_WORDS];
    int filtered_count;
    processor_filter(&processor, 0.1, filtered_vectors, &filtered_count);
    Analysis analysis;
    analysis_init(&analysis, filtered_vectors);
    double mean_vector[MAX_WORDS];
    double variance_vector[MAX_WORDS];
    analysis_analyze(&analysis, mean_vector, variance_vector);
    printf("Mean Vector: ");
    for (int j = 0; j < MAX_WORDS; j++) {
        printf("%f ", mean_vector[j]);
    }
    printf("\n");
    printf("Variance Vector: ");
    for (int j = 0; j < MAX_WORDS; j++) {
        printf("%f ", variance_vector[j]);
    }
    printf("\n");
}

int main() {
    main();
    return 0;
}