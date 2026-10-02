#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TOKENS 1000
#define MAX_TEXTS 10
#define MAX_WORD_LENGTH 50

typedef struct {
    char **corpus;
    char **tokenized;
    int *vocabulary;
    int **vectorized;
} TextVectorizor;

void TextVectorizor_init(TextVectorizor *self, char **corpus) {
    self->corpus = corpus;
    self->tokenized = (char **)malloc(MAX_TOKENS * sizeof(char *));
    self->vocabulary = (int *)malloc(MAX_TOKENS * sizeof(int));
    self->vectorized = (int **)malloc(MAX_TEXTS * sizeof(int *));
    for (int i = 0; i < MAX_TEXTS; i++) {
        self->vectorized[i] = (int *)malloc(MAX_TOKENS * sizeof(int));
    }
    self->tokenize(self);
    self->build_vocabulary(self);
    self->vectorize(self);
}

void TextVectorizor_tokenize(TextVectorizor *self) {
    int token_index = 0;
    for (int i = 0; i < MAX_TEXTS; i++) {
        char *text = self->corpus[i];
        char word[MAX_WORD_LENGTH];
        char *token = strtok(text, " ");
        while (token != NULL) {
            for (int j = 0; j < strlen(token); j++) {
                word[j] = tolower(token[j]);
            }
            word[strlen(token)] = '\0';
            self->tokenized[token_index++] = strdup(word);
            token = strtok(NULL, " ");
        }
    }
}

void TextVectorizor_build_vocabulary(TextVectorizor *self) {
    int vocab_index = 0;
    bool in_vocabulary[MAX_TOKENS] = {false};
    for (int i = 0; i < MAX_TOKENS; i++) {
        if (self->tokenized[i] != NULL && !in_vocabulary[i]) {
            in_vocabulary[i] = true;
            self->vocabulary[vocab_index++] = i;
        }
    }
}

void TextVectorizor_vectorize(TextVectorizor *self) {
    for (int i = 0; i < MAX_TEXTS; i++) {
        for (int j = 0; j < MAX_TOKENS; j++) {
            self->vectorized[i][j] = 0;
        }
        char *text = self->corpus[i];
        char word[MAX_WORD_LENGTH];
        char *token = strtok(text, " ");
        while (token != NULL) {
            for (int j = 0; j < strlen(token); j++) {
                word[j] = tolower(token[j]);
            }
            word[strlen(token)] = '\0';
            for (int j = 0; j < MAX_TOKENS; j++) {
                if (self->tokenized[j] != NULL && strcmp(word, self->tokenized[j]) == 0) {
                    self->vectorized[i][j]++;
                }
            }
            token = strtok(NULL, " ");
        }
    }
}

int **process_data() {
    static char *corpus[MAX_TEXTS] = {
        "The quick brown fox jumps over the lazy dog",
        "Never jump over the lazy dog quickly",
        "Quickly brown foxes never jump"
    };
    static TextVectorizor vectorizor;
    TextVectorizor_init(&vectorizor, corpus);
    return vectorizor.vectorized;
}

int *analyze_vectors(int **vectors) {
    static int analysis[MAX_TEXTS];
    for (int i = 0; i < MAX_TEXTS; i++) {
        analysis[i] = 0;
        for (int j = 0; j < MAX_TOKENS; j++) {
            analysis[i] += vectors[i][j];
        }
    }
    return analysis;
}

int main() {
    int **vectors = process_data();
    int *analysis = analyze_vectors(vectors);
    while (true) {
        int **new_vectors = process_data();
        int *new_analysis = analyze_vectors(new_vectors);
        bool changed = false;
        for (int i = 0; i < MAX_TEXTS; i++) {
            if (analysis[i] != new_analysis[i]) {
                changed = true;
                break;
            }
        }
        if (changed) {
            analysis = new_analysis;
            for (int i = 0; i < MAX_TEXTS; i++) {
                printf("%d ", analysis[i]);
            }
            printf("\n");
        }
    }
    return 0;
}