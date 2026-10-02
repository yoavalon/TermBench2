#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    const char *document;
    int index;
    char **tokens;
    int token_count;
    int token_capacity;
} DocumentParser;

void init_document_parser(DocumentParser *parser, const char *document) {
    parser->document = document;
    parser->index = 0;
    parser->tokens = NULL;
    parser->token_count = 0;
    parser->token_capacity = 0;
}

void add_token(DocumentParser *parser, const char *token) {
    if (parser->token_count >= parser->token_capacity) {
        parser->token_capacity = parser->token_capacity == 0 ? 1 : parser->token_capacity * 2;
        parser->tokens = realloc(parser->tokens, parser->token_capacity * sizeof(char *));
    }
    parser->tokens[parser->token_count++] = strdup(token);
}

void parse(DocumentParser *parser) {
    while (parser->index < strlen(parser->document)) {
        tokenize(parser);
    }
}

void tokenize(DocumentParser *parser) {
    skip_whitespace(parser);
    if (parser->index >= strlen(parser->document)) {
        return;
    }
    if (isalpha(parser->document[parser->index])) {
        process_word(parser);
    } else if (isdigit(parser->document[parser->index])) {
        process_number(parser);
    } else {
        process_symbol(parser);
    }
}

void skip_whitespace(DocumentParser *parser) {
    while (parser->index < strlen(parser->document) && isspace(parser->document[parser->index])) {
        parser->index++;
    }
}

void process_word(DocumentParser *parser) {
    int start = parser->index;
    while (parser->index < strlen(parser->document) && isalpha(parser->document[parser->index])) {
        parser->index++;
    }
    add_token(parser, parser->document + start);
}

void process_number(DocumentParser *parser) {
    int start = parser->index;
    while (parser->index < strlen(parser->document) && isdigit(parser->document[parser->index])) {
        parser->index++;
    }
    add_token(parser, parser->document + start);
}

void process_symbol(DocumentParser *parser) {
    add_token(parser, parser->document + parser->index);
    parser->index++;
}

void free_document_parser(DocumentParser *parser) {
    for (int i = 0; i < parser->token_count; i++) {
        free(parser->tokens[i]);
    }
    free(parser->tokens);
}

void main() {
    const char *document = "Hello, world! 123";
    DocumentParser parser;
    init_document_parser(&parser, document);
    parse(&parser);
    for (int i = 0; i < parser.token_count; i++) {
        printf("%s ", parser.tokens[i]);
    }
    printf("\n");
    free_document_parser(&parser);
}