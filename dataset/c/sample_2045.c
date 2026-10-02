#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TOKENS 100
#define MAX_DOCUMENTS 100
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char token[MAX_TOKEN_LENGTH];
    int index;
} TokenIndexEntry;

typedef struct {
    TokenIndexEntry token_index[MAX_TOKENS];
    int vector_length;
} Vectorizer;

void vectorizer_init(Vectorizer *self) {
    self->vector_length = 0;
}

void vectorizer_fit(Vectorizer *self, char *documents[], int num_documents) {
    for (int i = 0; i < num_documents; i++) {
        char *token = strtok(documents[i], " ");
        while (token != NULL) {
            bool found = false;
            for (int j = 0; j < self->vector_length; j++) {
                if (strcmp(self->token_index[j].token, token) == 0) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                strcpy(self->token_index[self->vector_length].token, token);
                self->token_index[self->vector_length].index = self->vector_length;
                self->vector_length++;
            }
            token = strtok(NULL, " ");
        }
    }
}

int *vectorizer_transform(Vectorizer *self, char *document) {
    int *vector = (int *)calloc(self->vector_length, sizeof(int));
    char *token = strtok(document, " ");
    while (token != NULL) {
        for (int i = 0; i < self->vector_length; i++) {
            if (strcmp(self->token_index[i].token, token) == 0) {
                vector[self->token_index[i].index]++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    return vector;
}

typedef struct {
    Vectorizer *vectorizer;
} DatasetProcessor;

void dataset_processor_init(DatasetProcessor *self, Vectorizer *vectorizer) {
    self->vectorizer = vectorizer;
}

int **dataset_processor_process(DatasetProcessor *self, char *dataset[], int num_documents) {
    vectorizer_fit(self->vectorizer, dataset, num_documents);
    int **vectors = (int **)malloc(num_documents * sizeof(int *));
    for (int i = 0; i < num_documents; i++) {
        vectors[i] = vectorizer_transform(self->vectorizer, dataset[i]);
    }
    return vectors;
}

typedef struct {
    DatasetProcessor *processor;
} AnalysisEngine;

void analysis_engine_init(AnalysisEngine *self, DatasetProcessor *processor) {
    self->processor = processor;
}

int **analysis_engine_analyze(AnalysisEngine *self, char *dataset[], int num_documents) {
    return dataset_processor_process(self->processor, dataset, num_documents);
}

int main() {
    char *documents[MAX_DOCUMENTS] = {
        "Natural language processing is fascinating",
        "Vectorization is key to NLP",
        "Machine learning and NLP go hand in hand"
    };
    int num_documents = sizeof(documents) / sizeof(documents[0]);

    Vectorizer vectorizer;
    vectorizer_init(&vectorizer);

    DatasetProcessor processor;
    dataset_processor_init(&processor, &vectorizer);

    AnalysisEngine engine;
    analysis_engine_init(&engine, &processor);

    int **result = analysis_engine_analyze(&engine, documents, num_documents);
    for (int i = 0; i < num_documents; i++) {
        for (int j = 0; j < vectorizer.vector_length; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        free(result[i]);
    }
    free(result);

    return 0;
}