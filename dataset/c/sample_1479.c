#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char text[1000];
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count;
} DocumentParser;

void DocumentParser_init(DocumentParser *self, const char *text) {
    strcpy(self->text, text);
    self->token_count = 0;
}

void DocumentParser_preprocess(DocumentParser *self) {
    for (int i = 0; self->text[i]; i++) {
        self->text[i] = tolower(self->text[i]);
        if (ispunct(self->text[i])) {
            self->text[i] = ' ';
        }
        if (self->text[i] == '\n') {
            self->text[i] = ' ';
        }
    }
}

void DocumentParser_tokenize(DocumentParser *self) {
    char *token = strtok(self->text, " ");
    while (token != NULL) {
        strncpy(self->tokens[self->token_count], token, MAX_TOKEN_LENGTH - 1);
        self->tokens[self->token_count][MAX_TOKEN_LENGTH - 1] = '\0';
        self->token_count++;
        token = strtok(NULL, " ");
    }
}

typedef struct {
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count;
    char mutated_tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
} TokenMutator;

void TokenMutator_init(TokenMutator *self, const char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int token_count) {
    for (int i = 0; i < token_count; i++) {
        strcpy(self->tokens[i], tokens[i]);
    }
    self->token_count = token_count;
}

void TokenMutator_mutate(TokenMutator *self) {
    for (int i = 0; i < self->token_count; i++) {
        if (strlen(self->tokens[i]) > 3) {
            strncpy(self->mutated_tokens[i], self->tokens[i], 3);
            self->mutated_tokens[i][3] = '\0';
        } else {
            for (int j = 0; j < strlen(self->tokens[i]); j++) {
                self->mutated_tokens[i][j] = self->tokens[i][strlen(self->tokens[i]) - j - 1];
            }
            self->mutated_tokens[i][strlen(self->tokens[i])] = '\0';
        }
    }
}

typedef struct {
    DocumentParser document;
} DataProcessor;

void DataProcessor_init(DataProcessor *self, const char *text) {
    DocumentParser_init(&self->document, text);
}

char** DataProcessor_process(DataProcessor *self) {
    DocumentParser_preprocess(&self->document);
    DocumentParser_tokenize(&self->document);
    TokenMutator mutator;
    TokenMutator_init(&mutator, self->document.tokens, self->document.token_count);
    TokenMutator_mutate(&mutator);
    return mutator.mutated_tokens;
}

int main() {
    const char *text_data = "This is a sample document. It contains several sentences.";
    DataProcessor processor;
    DataProcessor_init(&processor, text_data);
    char **result = DataProcessor_process(&processor);
    for (int i = 0; i < processor.document.token_count; i++) {
        printf("%s ", result[i]);
    }
    printf("\n");
    return 0;
}