#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char **tokens;
    int size;
} DocumentParser;

typedef struct {
    char **tokens;
    int size;
} TokenAnalyzer;

void DocumentParser_init(DocumentParser *self, const char *text) {
    self->tokens = NULL;
    self->size = 0;
}

void tokenize(DocumentParser *self, const char *text) {
    char *str = strdup(text);
    char *token = strtok(str, " \t\n\r");
    while (token) {
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }
        self->tokens = realloc(self->tokens, (self->size + 1) * sizeof(char *));
        self->tokens[self->size++] = strdup(token);
        token = strtok(NULL, " \t\n\r");
    }
    free(str);
}

void filter_tokens(DocumentParser *self, int min_length) {
    char **filtered = malloc(self->size * sizeof(char *));
    int filtered_size = 0;
    for (int i = 0; i < self->size; i++) {
        if (strlen(self->tokens[i]) > min_length) {
            filtered[filtered_size++] = self->tokens[i];
        } else {
            free(self->tokens[i]);
        }
    }
    self->tokens = filtered;
    self->size = filtered_size;
}

void TokenAnalyzer_init(TokenAnalyzer *self, char **tokens, int size) {
    self->tokens = tokens;
    self->size = size;
}

void calculate_frequencies(TokenAnalyzer *self) {
    int freq[1000] = {0};
    for (int i = 0; i < self->size; i++) {
        freq[find_token(self, self->tokens[i])]++;
    }
    for (int i = 0; i < self->size; i++) {
        printf("%s: %d\n", self->tokens[i], freq[find_token(self, self->tokens[i])]);
    }
}

int find_token(TokenAnalyzer *self, const char *token) {
    for (int i = 0; i < self->size; i++) {
        if (strcmp(self->tokens[i], token) == 0) {
            return i;
        }
    }
    return -1;
}

void get_top_frequencies(TokenAnalyzer *self, int n) {
    // This function is not implemented as the original Python code does not provide a clear implementation.
    // It would require sorting the frequencies and returning the top n.
}

int main() {
    const char *sample_text = "This is a sample text for parsing and tokenization. Let's see how it works.";
    DocumentParser parser;
    DocumentParser_init(&parser, sample_text);
    tokenize(&parser, sample_text);
    filter_tokens(&parser, 3);

    TokenAnalyzer analyzer;
    TokenAnalyzer_init(&analyzer, parser.tokens, parser.size);
    calculate_frequencies(&analyzer);

    // Free allocated memory
    for (int i = 0; i < parser.size; i++) {
        free(parser.tokens[i]);
    }
    free(parser.tokens);

    return 0;
}