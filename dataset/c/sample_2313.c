c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *text;
    char **tokens;
    int token_count;
} Tokenizer;

typedef struct {
    Tokenizer *tokenizer;
    char **parsed_data_keys;
    float *parsed_data_values;
    int parsed_data_count;
} DocumentParser;

typedef struct {
    DocumentParser *document_parser;
    char **analysis_results_keys;
    int *analysis_results_is_floating_point;
    int *analysis_results_precision;
    int analysis_results_count;
} Analyzer;

void Tokenizer_init(Tokenizer *self, const char *text) {
    self->text = strdup(text);
    self->tokens = NULL;
    self->token_count = 0;
}

void Tokenizer_tokenize(Tokenizer *self) {
    int buffer_size = 0;
    char buffer[1024];
    for (int i = 0; self->text[i] != '\0'; i++) {
        char c = self->text[i];
        if (isalnum(c)) {
            buffer[buffer_size++] = c;
        } else {
            if (buffer_size > 0) {
                self->tokens = realloc(self->tokens, (self->token_count + 1) * sizeof(char *));
                self->tokens[self->token_count++] = strdup(buffer);
                buffer_size = 0;
            }
            if (!isspace(c)) {
                self->tokens = realloc(self->tokens, (self->token_count + 1) * sizeof(char *));
                self->tokens[self->token_count++] = strdup(&c);
            }
        }
    }
    if (buffer_size > 0) {
        self->tokens = realloc(self->tokens, (self->token_count + 1) * sizeof(char *));
        self->tokens[self->token_count++] = strdup(buffer);
    }
}

void Tokenizer_free(Tokenizer *self) {
    free(self->text);
    for (int i = 0; i < self->token_count; i++) {
        free(self->tokens[i]);
    }
    free(self->tokens);
}

void DocumentParser_init(DocumentParser *self, Tokenizer *tokenizer) {
    self->tokenizer = tokenizer;
    self->parsed_data_keys = NULL;
    self->parsed_data_values = NULL;
    self->parsed_data_count = 0;
}

void DocumentParser_parse(DocumentParser *self) {
    Tokenizer_tokenize(self->tokenizer);
    self->parsed_data_keys = realloc(self->parsed_data_keys, self->tokenizer->token_count * sizeof(char *));
    self->parsed_data_values = realloc(self->parsed_data_values, self->tokenizer->token_count * sizeof(float));
    self->parsed_data_count = 0;
    for (int i = 0; i < self->tokenizer->token_count; i++) {
        if (isdigit(self->tokenizer->tokens[i][0]) || (self->tokenizer->tokens[i][0] == '-' && isdigit(self->tokenizer->tokens[i][1]))) {
            self->parsed_data_keys[self->parsed_data_count] = strdup(self->tokenizer->tokens[i]);
            self->parsed_data_values[self->parsed_data_count] = atof(self->tokenizer->tokens[i]);
            self->parsed_data_count++;
        }
    }
}

void DocumentParser_free(DocumentParser *self) {
    for (int i = 0; i < self->parsed_data_count; i++) {
        free(self->parsed_data_keys[i]);
    }
    free(self->parsed_data_keys);
    free(self->parsed_data_values);
}

void Analyzer_init(Analyzer *self, DocumentParser *document_parser) {
    self->document_parser = document_parser;
    self->analysis_results_keys = NULL;
    self->analysis_results_is_floating_point = NULL;
    self->analysis_results_precision = NULL;
    self->analysis_results_count = 0;
}

void Analyzer_analyze(Analyzer *self) {
    self->analysis_results_keys = realloc(self->analysis_results_keys, self->document_parser->parsed_data_count * sizeof(char *));
    self->analysis_results_is_floating_point = realloc(self->analysis_results_is_floating_point, self->document_parser->parsed_data_count * sizeof(int));
    self->analysis_results_precision = realloc(self->analysis_results_precision, self->document_parser->parsed_data_count * sizeof(int));
    self->analysis_results_count = 0;
    for (int i = 0; i < self->document_parser->parsed_data_count; i++) {
        self->analysis_results_keys[self->analysis_results_count] = strdup(self->document_parser->parsed_data_keys[i]);
        self->analysis_results_is_floating_point[self->analysis_results_count] = 1;
        self->analysis_results_precision[self->analysis_results_count] = 0;
        if (strchr(self->document_parser->parsed_data_keys[i], '.') != NULL) {
            self->analysis_results_precision[self->analysis_results_count] = strlen(strchr(self->document_parser->parsed_data_keys[i], '.')) - 1;
        }
        self->analysis_results_count++;
    }
}

void Analyzer_free(Analyzer *self) {
    for (int i = 0; i < self->analysis_results_count; i++) {
        free(self->analysis_results_keys[i]);
    }
    free(self->analysis_results_keys);
    free(self->analysis_results_is_floating_point);
    free(self->analysis_results_precision);
}

void main() {
    const char *text = "The value of pi is approximately 3.141592653589793";
    Tokenizer tokenizer;
    DocumentParser document_parser;
    Analyzer analyzer;
    Tokenizer_init(&tokenizer, text);
    DocumentParser_init(&document_parser, &tokenizer);
    Analyzer_init(&analyzer, &document_parser);
    while (1) {
        DocumentParser_parse(&document_parser);
        Analyzer_analyze(&analyzer);
        for (int i = 0; i < analyzer.analysis_results_count; i++) {
            printf("%s: is_floating_point=%d, precision=%d\n", analyzer.analysis_results_keys[i], analyzer.analysis_results_is_floating_point[i], analyzer.analysis_results_precision[i]);
        }
    }
    Tokenizer_free(&tokenizer);
    DocumentParser_free(&document_parser);
    Analyzer_free(&analyzer);
}