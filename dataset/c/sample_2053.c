#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char *text;
    char **tokens;
    int token_count;
} Tokenizer;

typedef struct {
    char *text;
    Tokenizer tokenizer;
} DocumentParser;

typedef struct {
    char **tokens;
    int token_count;
} PrecisionAnalyzer;

void tokenizer_init(Tokenizer *tokenizer, const char *text) {
    tokenizer->text = strdup(text);
    tokenizer->tokens = NULL;
    tokenizer->token_count = 0;
}

void tokenizer_tokenize(Tokenizer *tokenizer) {
    const char *delimiters = " \t\n\r";
    char *text_copy = strdup(tokenizer->text);
    char *token = strtok(text_copy, delimiters);
    int count = 0;
    while (token != NULL) {
        count++;
        token = strtok(NULL, delimiters);
    }
    tokenizer->tokens = (char **)malloc(count * sizeof(char *));
    tokenizer->token_count = count;
    char *text_copy2 = strdup(tokenizer->text);
    token = strtok(text_copy2, delimiters);
    int i = 0;
    while (token != NULL) {
        tokenizer->tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, delimiters);
    }
    free(text_copy);
    free(text_copy2);
}

void tokenizer_destroy(Tokenizer *tokenizer) {
    for (int i = 0; i < tokenizer->token_count; i++) {
        free(tokenizer->tokens[i]);
    }
    free(tokenizer->tokens);
    free(tokenizer->text);
}

void document_parser_init(DocumentParser *parser, const char *text) {
    parser->text = strdup(text);
    tokenizer_init(&parser->tokenizer, text);
}

void document_parser_parse(DocumentParser *parser) {
    tokenizer_tokenize(&parser->tokenizer);
}

void document_parser_destroy(DocumentParser *parser) {
    tokenizer_destroy(&parser->tokenizer);
    free(parser->text);
}

void precision_analyzer_init(PrecisionAnalyzer *analyzer, const char **tokens, int token_count) {
    analyzer->tokens = tokens;
    analyzer->token_count = token_count;
}

bool precision_analyzer_is_float(const char *token) {
    char *endptr;
    strtod(token, &endptr);
    return *endptr == '\0';
}

int precision_analyzer_analyze(PrecisionAnalyzer *analyzer) {
    int float_count = 0;
    for (int i = 0; i < analyzer->token_count; i++) {
        if (precision_analyzer_is_float(analyzer->tokens[i])) {
            float_count++;
        }
    }
    return float_count;
}

void precision_analyzer_destroy(PrecisionAnalyzer *analyzer) {
    // No resources to free in this simple example
}

void main() {
    const char *text = "The price of the item is 19.99 and the discount is 0.25.";
    DocumentParser parser;
    document_parser_init(&parser, text);
    document_parser_parse(&parser);
    PrecisionAnalyzer analyzer;
    precision_analyzer_init(&analyzer, (const char **)parser.tokenizer.tokens, parser.tokenizer.token_count);
    int result = precision_analyzer_analyze(&analyzer);
    printf("Number of floating-point numbers: %d\n", result);
    precision_analyzer_destroy(&analyzer);
    document_parser_destroy(&parser);
}

int main() {
    main();
    return 0;
}