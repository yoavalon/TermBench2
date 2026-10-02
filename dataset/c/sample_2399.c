#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char *text;
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count;
} DocumentParser;

void DocumentParser_init(DocumentParser *self, char *text) {
    self->text = text;
    self->token_count = 0;
}

void DocumentParser_tokenize(DocumentParser *self) {
    char *word = strtok(self->text, " ,.");
    while (word != NULL) {
        if (strlen(word) < MAX_TOKEN_LENGTH) {
            strcpy(self->tokens[self->token_count], word);
            self->token_count++;
        }
        word = strtok(NULL, " ,.");
    }
}

void DocumentParser_filter_tokens(DocumentParser *self, int min_length) {
    int new_count = 0;
    for (int i = 0; i < self->token_count; i++) {
        if (strlen(self->tokens[i]) >= min_length) {
            strcpy(self->tokens[new_count], self->tokens[i]);
            new_count++;
        }
    }
    self->token_count = new_count;
}

typedef struct {
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count;
    int analysis[MAX_TOKENS];
} TokenAnalyzer;

void TokenAnalyzer_init(TokenAnalyzer *self, char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int token_count) {
    for (int i = 0; i < token_count; i++) {
        strcpy(self->tokens[i], tokens[i]);
        self->analysis[i] = 0;
    }
    self->token_count = token_count;
}

void TokenAnalyzer_count_tokens(TokenAnalyzer *self) {
    for (int i = 0; i < self->token_count; i++) {
        for (int j = 0; j < self->token_count; j++) {
            if (strcmp(self->tokens[i], self->tokens[j]) == 0) {
                self->analysis[i]++;
            }
        }
    }
}

void TokenAnalyzer_update_analysis(TokenAnalyzer *self, char new_tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int new_token_count) {
    for (int i = 0; i < new_token_count; i++) {
        int found = 0;
        for (int j = 0; j < self->token_count; j++) {
            if (strcmp(self->tokens[j], new_tokens[i]) == 0) {
                self->analysis[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(self->tokens[self->token_count], new_tokens[i]);
            self->analysis[self->token_count] = 1;
            self->token_count++;
        }
    }
}

typedef struct {
    DocumentParser parser;
    TokenAnalyzer analyzer;
} DataProcessor;

void DataProcessor_init(DataProcessor *self, DocumentParser *parser, TokenAnalyzer *analyzer) {
    self->parser = *parser;
    self->analyzer = *analyzer;
}

void DataProcessor_process(DataProcessor *self) {
    DocumentParser_tokenize(&self->parser);
    TokenAnalyzer_count_tokens(&self->analyzer);
}

int main() {
    char text[] = "In a galaxy far, far away, the floating-point precision of Python is a topic of great interest.";
    DocumentParser parser;
    TokenAnalyzer analyzer;
    DataProcessor processor;

    DocumentParser_init(&parser, text);
    TokenAnalyzer_init(&analyzer, parser.tokens, parser.token_count);
    DataProcessor_init(&processor, &parser, &analyzer);

    while (1) {
        DataProcessor_process(&processor);
        for (int i = 0; i < analyzer.token_count; i++) {
            printf("%s: %d\n", analyzer.tokens[i], analyzer.analysis[i]);
        }
        char new_tokens[4][MAX_TOKEN_LENGTH] = {"precision", "Python", "interest", "galaxy"};
        TokenAnalyzer_update_analysis(&analyzer, new_tokens, 4);
        for (int i = 0; i < analyzer.token_count; i++) {
            printf("%s: %d\n", analyzer.tokens[i], analyzer.analysis[i]);
        }
    }

    return 0;
}