#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DOCS 100
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int index;
} VocabularyEntry;

typedef struct {
    char** corpus;
    int corpus_size;
    VocabularyEntry vocabulary[MAX_WORDS];
    int vocabulary_size;
    int inverted_index[MAX_WORDS][MAX_DOCS];
    int inverted_index_size[MAX_WORDS];
} Vectorizer;

void init_vectorizer(Vectorizer* v, char** corpus, int corpus_size) {
    v->corpus = corpus;
    v->corpus_size = corpus_size;
    v->vocabulary_size = 0;
    v->inverted_index_size[0] = 0;
}

void build_vocabulary(Vectorizer* v) {
    char* words[MAX_WORDS];
    int word_count = 0;

    for (int i = 0; i < v->corpus_size; i++) {
        char* token = strtok(v->corpus[i], " ");
        while (token != NULL) {
            int is_new = 1;
            for (int j = 0; j < v->vocabulary_size; j++) {
                if (strcmp(v->vocabulary[j].word, token) == 0) {
                    is_new = 0;
                    break;
                }
            }
            if (is_new) {
                strcpy(v->vocabulary[v->vocabulary_size].word, token);
                v->vocabulary[v->vocabulary_size].index = v->vocabulary_size;
                v->vocabulary_size++;
            }
            token = strtok(NULL, " ");
        }
    }
}

void create_inverted_index(Vectorizer* v) {
    for (int i = 0; i < v->corpus_size; i++) {
        char* token = strtok(v->corpus[i], " ");
        while (token != NULL) {
            for (int j = 0; j < v->vocabulary_size; j++) {
                if (strcmp(v->vocabulary[j].word, token) == 0) {
                    v->inverted_index[v->vocabulary[j].index][v->inverted_index_size[v->vocabulary[j].index]] = i;
                    v->inverted_index_size[v->vocabulary[j].index]++;
                    break;
                }
            }
            token = strtok(NULL, " ");
        }
    }
}

double* vectorize_document(Vectorizer* v, char* document) {
    double* vector = (double*)calloc(v->vocabulary_size, sizeof(double));
    char* token = strtok(document, " ");
    while (token != NULL) {
        for (int j = 0; j < v->vocabulary_size; j++) {
            if (strcmp(v->vocabulary[j].word, token) == 0) {
                vector[v->vocabulary[j].index]++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    return vector;
}

double** process_corpus(Vectorizer* v) {
    double** vectors = (double**)malloc(v->corpus_size * sizeof(double*));
    for (int i = 0; i < v->corpus_size; i++) {
        vectors[i] = vectorize_document(v, v->corpus[i]);
    }
    return vectors;
}

void analyze_vectors(double** vectors, int corpus_size) {
    while (1) {
        for (int i = 0; i < corpus_size; i++) {
            double norm = 0.0;
            for (int j = 0; j < vectors[i][0]; j++) {
                norm += vectors[i][j] * vectors[i][j];
            }
            norm = sqrt(norm);
            printf("%f\n", norm);
        }
        for (int i = 0; i < corpus_size; i++) {
            for (int j = 0; j < vectors[i][0]; j++) {
                vectors[i][j] += ((double)rand() / RAND_MAX);
            }
        }
    }
}

int main() {
    char* corpus[MAX_DOCS] = {
        "the quick brown fox jumps over the lazy dog",
        "never jump over the lazy dog quickly",
        "foxes are quick and cunning animals"
    };
    int corpus_size = 3;

    Vectorizer v;
    init_vectorizer(&v, corpus, corpus_size);
    build_vocabulary(&v);
    create_inverted_index(&v);

    double** vectors = process_corpus(&v);
    analyze_vectors(vectors, corpus_size);

    return 0;
}