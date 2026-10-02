#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define ALPHABET_SIZE 26

typedef struct {
    char** data;
    int data_count;
    int** vectorized_data;
    int vectorized_data_count;
} Vectorizer;

typedef struct {
    char** data;
    int data_count;
    char** processed_data;
    int processed_data_count;
} DatasetProcessor;

void vectorizer_init(Vectorizer* v, char** data, int data_count) {
    v->data = data;
    v->data_count = data_count;
    v->vectorized_data = NULL;
    v->vectorized_data_count = 0;
}

char** tokenize(const char* text, int* token_count) {
    char** tokens = malloc(MAX_WORD_LENGTH * sizeof(char*));
    char* str = strdup(text);
    char* token = strtok(str, " ");
    *token_count = 0;
    while (token != NULL) {
        tokens[(*token_count)++] = strdup(token);
        token = strtok(NULL, " ");
    }
    free(str);
    return tokens;
}

int* vectorize_word(const char* word) {
    int* vector = calloc(ALPHABET_SIZE, sizeof(int));
    for (int i = 0; word[i] != '\0'; i++) {
        char c = tolower(word[i]);
        if ('a' <= c && c <= 'z') {
            vector[c - 'a']++;
        }
    }
    return vector;
}

void vectorizer_process(Vectorizer* v) {
    for (int i = 0; i < v->data_count; i++) {
        int token_count;
        char** tokens = tokenize(v->data[i], &token_count);
        for (int j = 0; j < token_count; j++) {
            int* vector = vectorize_word(tokens[j]);
            v->vectorized_data = realloc(v->vectorized_data, (v->vectorized_data_count + 1) * sizeof(int*));
            v->vectorized_data[v->vectorized_data_count++] = vector;
            free(tokens[j]);
        }
        free(tokens);
    }
}

void dataset_processor_init(DatasetProcessor* dp, char** data, int data_count) {
    dp->data = data;
    dp->data_count = data_count;
    dp->processed_data = NULL;
    dp->processed_data_count = 0;
}

char* normalize(const char* text) {
    char* normalized_text = malloc(strlen(text) + 1);
    int j = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalnum(text[i]) || isspace(text[i])) {
            normalized_text[j++] = text[i];
        }
    }
    normalized_text[j] = '\0';
    return normalized_text;
}

void dataset_processor_process(DatasetProcessor* dp) {
    for (int i = 0; i < dp->data_count; i++) {
        char* normalized_text = normalize(dp->data[i]);
        dp->processed_data = realloc(dp->processed_data, (dp->processed_data_count + 1) * sizeof(char*));
        dp->processed_data[dp->processed_data_count++] = normalized_text;
    }
}

void main() {
    char* raw_data[] = {"Hello world!", "Data Science is fun.", "Recursive vectorization."};
    int data_count = sizeof(raw_data) / sizeof(raw_data[0]);

    DatasetProcessor processor;
    dataset_processor_init(&processor, raw_data, data_count);
    dataset_processor_process(&processor);

    Vectorizer vectorizer;
    vectorizer_init(&vectorizer, processor.processed_data, processor.processed_data_count);
    vectorizer_process(&vectorizer);

    for (int i = 0; i < vectorizer.vectorized_data_count; i++) {
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            printf("%d ", vectorizer.vectorized_data[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < processor.processed_data_count; i++) {
        free(processor.processed_data[i]);
    }
    free(processor.processed_data);
    for (int i = 0; i < vectorizer.vectorized_data_count; i++) {
        free(vectorizer.vectorized_data[i]);
    }
    free(vectorizer.vectorized_data);
}