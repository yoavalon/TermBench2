#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TOKENS 1000
#define MAX_DELIMITERS 5
#define MAX_TEXT_LENGTH 1000

typedef struct {
    char *text;
    char tokens[MAX_TOKENS][MAX_TEXT_LENGTH];
    int index;
    char delimiters[MAX_DELIMITERS];
    int token_count;
} Tokenizer;

typedef struct {
    Tokenizer *tokenizer;
    int parsed_data[MAX_TEXT_LENGTH];
} Parser;

typedef struct {
    char *text;
    Tokenizer tokenizer;
    Parser parser;
} DocumentAnalyzer;

void tokenizer_init(Tokenizer *tokenizer, char *text) {
    tokenizer->text = text;
    tokenizer->index = 0;
    tokenizer->delimiters[0] = ' ';
    tokenizer->delimiters[1] = '.';
    tokenizer->delimiters[2] = ',';
    tokenizer->delimiters[3] = '!';
    tokenizer->delimiters[4] = '?';
    tokenizer->token_count = 0;
}

bool is_delimiter(char char, char delimiters[MAX_DELIMITERS], int delimiter_count) {
    for (int i = 0; i < delimiter_count; i++) {
        if (char == delimiters[i]) {
            return true;
        }
    }
    return false;
}

void next_token(Tokenizer *tokenizer) {
    char token[MAX_TEXT_LENGTH] = "";
    while (tokenizer->index < strlen(tokenizer->text)) {
        char char = tokenizer->text[tokenizer->index];
        if (is_delimiter(char, tokenizer->delimiters, MAX_DELIMITERS)) {
            if (strlen(token) > 0) {
                strcpy(tokenizer->tokens[tokenizer->token_count], token);
                tokenizer->token_count++;
                memset(token, 0, MAX_TEXT_LENGTH);
            }
            tokenizer->tokens[tokenizer->token_count][0] = char;
            tokenizer->tokens[tokenizer->token_count][1] = '\0';
            tokenizer->token_count++;
        } else {
            strncat(token, &char, 1);
        }
        tokenizer->index++;
    }
    if (strlen(token) > 0) {
        strcpy(tokenizer->tokens[tokenizer->token_count], token);
        tokenizer->token_count++;
    }
}

void parser_init(Parser *parser, Tokenizer *tokenizer) {
    parser->tokenizer = tokenizer;
    memset(parser->parsed_data, 0, sizeof(parser->parsed_data));
}

void parse(Parser *parser) {
    next_token(parser->tokenizer);
    for (int i = 0; i < parser->tokenizer->token_count; i++) {
        char *token = parser->tokenizer->tokens[i];
        int hash = 0;
        for (int j = 0; j < strlen(token); j++) {
            hash = (hash * 31 + token[j]) % MAX_TEXT_LENGTH;
        }
        parser->parsed_data[hash]++;
    }
}

void document_analyzer_init(DocumentAnalyzer *analyzer, char *text) {
    analyzer->text = text;
    tokenizer_init(&analyzer->tokenizer, text);
    parser_init(&analyzer->parser, &analyzer->tokenizer);
}

void analyze(DocumentAnalyzer *analyzer) {
    parse(&analyzer->parser);
}

int main() {
    char text[] = "Hello, world! This is a test. Hello again.";
    DocumentAnalyzer analyzer;
    document_analyzer_init(&analyzer, text);
    while (1) {
        analyze(&analyzer);
        for (int i = 0; i < MAX_TEXT_LENGTH; i++) {
            if (analyzer.parser.parsed_data[i] > 0) {
                printf("%s: %d\n", analyzer.tokenizer.tokens[i], analyzer.parser.parsed_data[i]);
            }
        }
    }
    return 0;
}