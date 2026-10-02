#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_DOCUMENTS 5
#define MAX_DOCUMENT_LENGTH 100

typedef struct {
    char documents[NUM_DOCUMENTS][MAX_DOCUMENT_LENGTH];
    double vectorizer[NUM_DOCUMENTS][NUM_DOCUMENTS];
} DataProcessor;

typedef struct {
    double vectorized_data[NUM_DOCUMENTS][NUM_DOCUMENTS];
} ModelEvaluator;

typedef struct {
    double norms[NUM_DOCUMENTS];
} ResultAnalyzer;

void DataProcessor_init(DataProcessor *self, const char *documents[]) {
    for (int i = 0; i < NUM_DOCUMENTS; i++) {
        strcpy(self->documents[i], documents[i]);
    }
}

void DataProcessor_fit_transform(DataProcessor *self) {
    for (int i = 0; i < NUM_DOCUMENTS; i++) {
        for (int j = 0; j < NUM_DOCUMENTS; j++) {
            self->vectorizer[i][j] = 1.0; // Placeholder for TF-IDF calculation
        }
    }
}

void ModelEvaluator_init(ModelEvaluator *self, double vectorized_data[NUM_DOCUMENTS][NUM_DOCUMENTS]) {
    for (int i = 0; i < NUM_DOCUMENTS; i++) {
        for (int j = 0; j < NUM_DOCUMENTS; j++) {
            self->vectorized_data[i][j] = vectorized_data[i][j];
        }
    }
}

void ModelEvaluator_evaluate(ModelEvaluator *self, double norms[NUM_DOCUMENTS]) {
    for (int i = 0; i < NUM_DOCUMENTS; i++) {
        norms[i] = 0.0;
        for (int j = 0; j < NUM_DOCUMENTS; j++) {
            norms[i] += self->vectorized_data[i][j] * self->vectorized_data[i][j];
        }
        norms[i] = sqrt(norms[i]);
    }
}

void ResultAnalyzer_init(ResultAnalyzer *self, double norms[NUM_DOCUMENTS]) {
    for (int i = 0; i < NUM_DOCUMENTS; i++) {
        self->norms[i] = norms[i];
    }
}

void ResultAnalyzer_analyze(ResultAnalyzer *self, double *mean, double *std, double *max_norm, double *min_norm) {
    *mean = 0.0;
    for (int i = 0; i < NUM_DOCUMENTS; i++) {
        *mean += self->norms[i];
    }
    *mean /= NUM_DOCUMENTS;

    *std = 0.0;
    for (int i = 0; i < NUM_DOCUMENTS; i++) {
        *std += (self->norms[i] - *mean) * (self->norms[i] - *mean);
    }
    *std = sqrt(*std / NUM_DOCUMENTS);

    *max_norm = self->norms[0];
    for (int i = 1; i < NUM_DOCUMENTS; i++) {
        if (self->norms[i] > *max_norm) {
            *max_norm = self->norms[i];
        }
    }

    *min_norm = self->norms[0];
    for (int i = 1; i < NUM_DOCUMENTS; i++) {
        if (self->norms[i] < *min_norm) {
            *min_norm = self->norms[i];
        }
    }
}

int main() {
    const char *documents[NUM_DOCUMENTS] = {
        "Python is a great programming language",
        "Machine learning with Python is fascinating",
        "Natural language processing is a complex field",
        "Vectorization is a key concept in NLP",
        "Understanding floating point precision is crucial"
    };

    DataProcessor processor;
    DataProcessor_init(&processor, documents);
    DataProcessor_fit_transform(&processor);

    ModelEvaluator evaluator;
    ModelEvaluator_init(&evaluator, processor.vectorizer);
    double norms[NUM_DOCUMENTS];
    ModelEvaluator_evaluate(&evaluator, norms);

    ResultAnalyzer analyzer;
    ResultAnalyzer_init(&analyzer, norms);
    double mean, std, max_norm, min_norm;
    ResultAnalyzer_analyze(&analyzer, &mean, &std, &max_norm, &min_norm);

    printf("Mean Norm: %f\n", mean);
    printf("Standard Deviation: %f\n", std);
    printf("Max Norm: %f\n", max_norm);
    printf("Min Norm: %f\n", min_norm);

    return 0;
}