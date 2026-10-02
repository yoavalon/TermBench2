#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char* text;
    char tokens[1000];
    int token_count;
} DocumentTokenizer;

void DocumentTokenizer_init(DocumentTokenizer* self, char* text) {
    self->text = text;
    self->token_count = 0;
}

void DocumentTokenizer_tokenize(DocumentTokenizer* self) {
    for (int i = 0; i < strlen(self->text); i++) {
        char c = self->text[i];
        if (isalnum(c) || isspace(c)) {
            self->tokens[self->token_count++] = c;
        } else {
            self->tokens[self->token_count++] = ' ';
        }
    }
}

void DocumentTokenizer_filter_tokens(DocumentTokenizer* self) {
    char filtered_tokens[1000];
    int filtered_count = 0;
    char word[100];
    int word_index = 0;

    for (int i = 0; i < self->token_count; i++) {
        char c = self->tokens[i];
        if (isalnum(c)) {
            word[word_index++] = c;
        } else if (isspace(c) && word_index > 0) {
            for (int j = 0; j < word_index; j++) {
                filtered_tokens[filtered_count++] = word[j];
            }
            filtered_tokens[filtered_count++] = ' ';
            word_index = 0;
        }
    }
    if (word_index > 0) {
        for (int j = 0; j < word_index; j++) {
            filtered_tokens[filtered_count++] = word[j];
        }
    }

    self->token_count = filtered_count;
    for (int i = 0; i < filtered_count; i++) {
        self->tokens[i] = filtered_tokens[i];
    }
}

typedef struct {
    DocumentTokenizer* tokenizer;
    char tokens[1000];
    int token_count;
} DataMutator;

void DataMutator_init(DataMutator* self, DocumentTokenizer* tokenizer) {
    self->tokenizer = tokenizer;
}

void DataMutator_mutate(DataMutator* self) {
    DocumentTokenizer_tokenize(self->tokenizer);
    DocumentTokenizer_filter_tokens(self->tokenizer);
    self->token_count = self->tokenizer->token_count;
    for (int i = 0; i < self->token_count; i++) {
        self->tokens[i] = self->tokenizer->tokens[i];
    }
}

int main() {
    char text[] = "Hello, world! This is a test.";
    DocumentTokenizer tokenizer;
    DataMutator mutator;

    DocumentTokenizer_init(&tokenizer, text);
    DataMutator_init(&mutator, &tokenizer);
    DataMutator_mutate(&mutator);

    for (int i = 0; i < mutator.token_count; i++) {
        printf("%c", mutator.tokens[i]);
    }
    printf("\n");

    return 0;
}