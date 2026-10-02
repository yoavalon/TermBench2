#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char **data;
    int *vectors;
    int data_size;
    int vector_size;
} Vectorizer;

typedef struct {
    Vectorizer *vectorizer;
} Processor;

typedef struct {
    Vectorizer vectorizer;
    Processor processor;
    char **data;
    int data_size;
} Main;

void vectorizer_init(Vectorizer *self, char **data, int data_size) {
    self->data = data;
    self->data_size = data_size;
    self->vectors = NULL;
    self->vector_size = 0;
}

void vectorizer_preprocess(Vectorizer *self) {
    for (int i = 0; i < self->data_size; i++) {
        char *text = self->data[i];
        int len = strlen(text);
        char *tokenized = (char *)malloc(len + 1);
        int j = 0;
        for (int k = 0; k < len; k++) {
            tokenized[j++] = tolower(text[k]);
        }
        tokenized[j] = '\0';
        self->data[i] = tokenized;
    }
}

char **vectorizer_tokenize(Vectorizer *self, char *text) {
    char **tokens = (char **)malloc(strlen(text) * sizeof(char *));
    int token_count = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        tokens[token_count++] = token;
        token = strtok(NULL, " ");
    }
    return tokens;
}

void vectorizer_vectorize(Vectorizer *self) {
    self->vector_size = self->data_size * strlen(self->data[0]);
    self->vectors = (int *)malloc(self->vector_size * sizeof(int));
    for (int i = 0; i < self->data_size; i++) {
        char **tokens = vectorizer_tokenize(self, self->data[i]);
        int *vector = vectorizer_create_vector(self, tokens);
        for (int j = 0; j < strlen(self->data[i]); j++) {
            self->vectors[i * strlen(self->data[i]) + j] = vector[j];
        }
        free(tokens);
    }
}

int *vectorizer_create_vector(Vectorizer *self, char **tokens) {
    int *vector = (int *)calloc(strlen(self->data[0]), sizeof(int));
    for (int i = 0; i < strlen(self->data[0]); i++) {
        for (int j = 0; j < strlen(self->data[0]); j++) {
            if (strcmp(tokens[i], self->data[0][j]) == 0) {
                vector[j]++;
            }
        }
    }
    return vector;
}

char **vectorizer_vocabulary(Vectorizer *self) {
    char **vocab = (char **)malloc(strlen(self->data[0]) * sizeof(char *));
    int vocab_count = 0;
    for (int i = 0; i < self->data_size; i++) {
        for (int j = 0; j < strlen(self->data[0]); j++) {
            int found = 0;
            for (int k = 0; k < vocab_count; k++) {
                if (strcmp(vocab[k], self->data[i][j]) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                vocab[vocab_count++] = self->data[i][j];
            }
        }
    }
    return vocab;
}

void processor_init(Processor *self, Vectorizer *vectorizer) {
    self->vectorizer = vectorizer;
}

int *processor_run(Processor *self) {
    vectorizer_preprocess(self->vectorizer);
    vectorizer_vectorize(self->vectorizer);
    return self->vectorizer->vectors;
}

void main_init(Main *self) {
    self->data = (char **)malloc(3 * sizeof(char *));
    self->data[0] = "Hello world";
    self->data[1] = "This is a test";
    self->data[2] = "Natural language processing";
    self->data_size = 3;
    vectorizer_init(&self->vectorizer, self->data, self->data_size);
    processor_init(&self->processor, &self->vectorizer);
}

void main_execute(Main *self) {
    int *vectors = processor_run(&self->processor);
    for (int i = 0; i < self->vectorizer.vector_size; i++) {
        printf("%d ", vectors[i]);
    }
    printf("\n");
}

int main() {
    Main main_instance;
    main_init(&main_instance);
    main_execute(&main_instance);
    return 0;
}