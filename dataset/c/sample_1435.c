#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE 3
#define VECTOR_SIZE 100

typedef struct {
    char **data;
    double **vectors;
} Vectorizer;

typedef struct {
    char *word;
    double *vector;
} VocabularyEntry;

VocabularyEntry **vocabulary;
int vocabulary_size = 0;

void vectorizer_init(Vectorizer *vectorizer, char **data) {
    vectorizer->data = data;
    vectorizer->vectors = (double **)malloc(DATA_SIZE * sizeof(double *));
    for (int i = 0; i < DATA_SIZE; i++) {
        vectorizer->vectors[i] = (double *)calloc(VECTOR_SIZE, sizeof(double));
    }
}

void preprocess(char **data) {
    for (int i = 0; i < DATA_SIZE; i++) {
        for (int j = 0; j < strlen(data[i]); j++) {
            data[i][j] = tolower(data[i][j]);
        }
    }
}

void transform(Vectorizer *vectorizer) {
    for (int i = 0; i < DATA_SIZE; i++) {
        char *token = strtok(vectorizer->data[i], " ");
        while (token != NULL) {
            for (int j = 0; j < vocabulary_size; j++) {
                if (strcmp(vocabulary[j]->word, token) == 0) {
                    for (int k = 0; k < VECTOR_SIZE; k++) {
                        vectorizer->vectors[i][k] += vocabulary[j]->vector[k];
                    }
                }
            }
            token = strtok(NULL, " ");
        }
    }
}

void build_vocabulary(Vectorizer *vectorizer) {
    vocabulary = (VocabularyEntry **)malloc(DATA_SIZE * sizeof(VocabularyEntry *));
    for (int i = 0; i < DATA_SIZE; i++) {
        char *token = strtok(vectorizer->data[i], " ");
        while (token != NULL) {
            int found = 0;
            for (int j = 0; j < vocabulary_size; j++) {
                if (strcmp(vocabulary[j]->word, token) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                vocabulary[vocabulary_size] = (VocabularyEntry *)malloc(sizeof(VocabularyEntry));
                vocabulary[vocabulary_size]->word = (char *)malloc(strlen(token) + 1);
                strcpy(vocabulary[vocabulary_size]->word, token);
                vocabulary[vocabulary_size]->vector = (double *)malloc(VECTOR_SIZE * sizeof(double));
                for (int k = 0; k < VECTOR_SIZE; k++) {
                    vocabulary[vocabulary_size]->vector[k] = (double)rand() / RAND_MAX;
                }
                vocabulary_size++;
            }
            token = strtok(NULL, " ");
        }
    }
}

double **fit_transform(Vectorizer *vectorizer) {
    preprocess(vectorizer->data);
    build_vocabulary(vectorizer);
    transform(vectorizer);
    return vectorizer->vectors;
}

char **load_data() {
    char **data = (char **)malloc(DATA_SIZE * sizeof(char *));
    data[0] = "Example sentence one";
    data[1] = "Another example sentence two";
    data[2] = "Yet another example";
    return data;
}

int main() {
    srand(time(NULL));
    char **data = load_data();
    Vectorizer vectorizer;
    vectorizer_init(&vectorizer, data);
    double **vectors = fit_transform(&vectorizer);
    for (int i = 0; i < DATA_SIZE; i++) {
        for (int j = 0; j < VECTOR_SIZE; j++) {
            printf("%f ", vectors[i][j]);
        }
        printf("\n");
    }
    return 0;
}