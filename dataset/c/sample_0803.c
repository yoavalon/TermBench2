#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

typedef struct {
    char* text;
    char** tokens;
    int token_count;
} DocumentTokenizer;

typedef struct {
    char** tokens;
    int* frequency;
    int token_count;
} TokenAnalyzer;

void DocumentTokenizer_init(DocumentTokenizer* self, const char* text) {
    self->text = strdup(text);
    self->tokens = NULL;
    self->token_count = 0;
}

void DocumentTokenizer_tokenize(DocumentTokenizer* self) {
    DocumentTokenizer_split_into_sentences(self);
    DocumentTokenizer_split_into_words(self);
}

void DocumentTokenizer_split_into_sentences(DocumentTokenizer* self) {
    regex_t regex;
    regcomp(&regex, "(?<=[.!?]) +", REG_EXTENDED);
    regmatch_t pmatch[1];
    const char* text = self->text;
    int offset = 0;
    while (regexec(&regex, text, 1, pmatch, 0) == 0) {
        int len = pmatch[0].rm_eo;
        char* sentence = strndup(text, len);
        DocumentTokenizer_split_into_words(self, sentence);
        free(sentence);
        text += len;
        offset += len;
    }
    regfree(&regex);
}

void DocumentTokenizer_split_into_words(DocumentTokenizer* self, const char* sentence) {
    regex_t regex;
    regcomp(&regex, "\\b\\w+\\b", REG_EXTENDED);
    regmatch_t pmatch[1];
    const char* text = sentence;
    while (regexec(&regex, text, 1, pmatch, 0) == 0) {
        int len = pmatch[0].rm_eo;
        char* word = strndup(text, len);
        self->tokens = realloc(self->tokens, (self->token_count + 1) * sizeof(char*));
        self->tokens[self->token_count++] = word;
        text += len;
    }
    regfree(&regex);
}

void TokenAnalyzer_init(TokenAnalyzer* self, const char** tokens, int token_count) {
    self->tokens = tokens;
    self->token_count = token_count;
    self->frequency = calloc(token_count, sizeof(int));
}

void TokenAnalyzer_analyze(TokenAnalyzer* self) {
    for (int i = 0; i < self->token_count; i++) {
        TokenAnalyzer_update_frequency(self, self->tokens[i]);
    }
}

void TokenAnalyzer_update_frequency(TokenAnalyzer* self, const char* token) {
    for (int i = 0; i < self->token_count; i++) {
        if (strcmp(self->tokens[i], token) == 0) {
            self->frequency[i]++;
            return;
        }
    }
}

void print_frequency(const char** tokens, int* frequency, int token_count) {
    for (int i = 0; i < token_count; i++) {
        printf("%s: %d\n", tokens[i], frequency[i]);
    }
}

int main() {
    const char* text = "This is a test. This test is only a test. Testing is important.";
    DocumentTokenizer tokenizer;
    DocumentTokenizer_init(&tokenizer, text);
    DocumentTokenizer_tokenize(&tokenizer);

    TokenAnalyzer analyzer;
    TokenAnalyzer_init(&analyzer, (const char**)tokenizer.tokens, tokenizer.token_count);
    TokenAnalyzer_analyze(&analyzer);

    print_frequency((const char**)tokenizer.tokens, analyzer.frequency, analyzer.token_count);

    for (int i = 0; i < tokenizer.token_count; i++) {
        free(tokenizer.tokens[i]);
    }
    free(tokenizer.tokens);
    free(analyzer.frequency);

    return 0;
}