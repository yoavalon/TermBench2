#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char **data;
    int size;
} Dataset;

typedef struct {
    char **data;
    double **vectorized_data;
    int size;
} Vectorizer;

void tokenize(char *item, char *tokens[], int *token_count) {
    char *token = strtok(item, " ");
    *token_count = 0;
    while (token != NULL && *token_count < MAX_TOKENS) {
        tokens[*token_count] = token;
        token = strtok(NULL, " ");
        (*token_count)++;
    }
}

double embed_token(char *token) {
    int length = strlen(token);
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += (double)token[i];
    }
    return sum / length;
}

void embed(char *tokens[], double vector[], int token_count) {
    for (int i = 0; i < token_count; i++) {
        vector[i] = embed_token(tokens[i]);
    }
}

void transform(char *item, double vector[], int *vector_size) {
    char *tokens[MAX_TOKENS];
    int token_count;
    tokenize(item, tokens, &token_count);
    embed(tokens, vector, token_count);
    *vector_size = token_count;
}

void process(Vectorizer *vectorizer) {
    for (int i = 0; i < vectorizer->size; i++) {
        double *vector = malloc(vectorizer->data[i] * sizeof(double));
        int vector_size;
        transform(vectorizer->data[i], vector, &vector_size);
        vectorizer->vectorized_data[i] = vector;
    }
}

Vectorizer* vectorizer_init(char *data[], int size) {
    Vectorizer *vectorizer = malloc(sizeof(Vectorizer));
    vectorizer->data = data;
    vectorizer->size = size;
    vectorizer->vectorized_data = malloc(size * sizeof(double *));
    return vectorizer;
}

void remove_punctuation(char *item) {
    char *src = item, *dst = item;
    while (*src) {
        if (strchr("!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~", *src) == NULL) {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
}

void preprocess(char *item) {
    for (int i = 0; i < strlen(item); i++) {
        item[i] = tolower(item[i]);
    }
    remove_punctuation(item);
}

char** clean(Dataset *dataset) {
    char **cleaned_data = malloc(dataset->size * sizeof(char *));
    for (int i = 0; i < dataset->size; i++) {
        cleaned_data[i] = dataset->data[i];
        preprocess(cleaned_data[i]);
    }
    return cleaned_data;
}

Dataset* dataset_init(char *raw_data[], int size) {
    Dataset *dataset = malloc(sizeof(Dataset));
    dataset->raw_data = raw_data;
    dataset->size = size;
    return dataset;
}

void print_vectorized_data(Vectorizer *vectorizer) {
    for (int i = 0; i < vectorizer->size; i++) {
        printf("[");
        for (int j = 0; j < strlen(vectorizer->data[i]) / 2 + 1; j++) {
            printf("%f ", vectorizer->vectorized_data[i][j]);
        }
        printf("]\n");
    }
}

int main() {
    char *raw_data[] = {"Hello, world!", "Natural language processing is fascinating.", "Recursion can be tricky."};
    int size = sizeof(raw_data) / sizeof(raw_data[0]);
    Dataset *dataset = dataset_init(raw_data, size);
    char **cleaned_data = clean(dataset);
    Vectorizer *vectorizer = vectorizer_init(cleaned_data, size);
    process(vectorizer);
    print_vectorized_data(vectorizer);
    return 0;
}