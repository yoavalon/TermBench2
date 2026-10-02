#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TOKENS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char tokens[MAX_TOKENS][MAX_WORD_LENGTH];
    int token_count[MAX_TOKENS];
    int count;
} TokenAnalyzer;

typedef struct {
    char text[1000];
    char tokens[MAX_TOKENS][MAX_WORD_LENGTH];
    int token_count;
} DocumentParser;

void tokenize(DocumentParser *parser) {
    char *delimiters = " .,!?;:";
    char *token = strtok(parser->text, delimiters);
    parser->token_count = 0;
    while (token != NULL && parser->token_count < MAX_TOKENS) {
        for (int i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }
        strcpy(parser->tokens[parser->token_count], token);
        parser->token_count++;
        token = strtok(NULL, delimiters);
    }
}

void analyze_tokens(TokenAnalyzer *analyzer, DocumentParser *parser) {
    analyzer->count = 0;
    for (int i = 0; i < parser->token_count; i++) {
        bool found = false;
        for (int j = 0; j < analyzer->count; j++) {
            if (strcmp(analyzer->tokens[j], parser->tokens[i]) == 0) {
                analyzer->token_count[j]++;
                found = true;
                break;
            }
        }
        if (!found && analyzer->count < MAX_TOKENS) {
            strcpy(analyzer->tokens[analyzer->count], parser->tokens[i]);
            analyzer->token_count[analyzer->count] = 1;
            analyzer->count++;
        }
    }
}

void generate_report(TokenAnalyzer *analyzer) {
    for (int i = 0; i < analyzer->count - 1; i++) {
        for (int j = i + 1; j < analyzer->count; j++) {
            if (analyzer->token_count[i] < analyzer->token_count[j]) {
                int temp_count = analyzer->token_count[i];
                analyzer->token_count[i] = analyzer->token_count[j];
                analyzer->token_count[j] = temp_count;
                char temp_token[MAX_WORD_LENGTH];
                strcpy(temp_token, analyzer->tokens[i]);
                strcpy(analyzer->tokens[i], analyzer->tokens[j]);
                strcpy(analyzer->tokens[j], temp_token);
            }
        }
    }
}

void main() {
    DocumentParser parser;
    TokenAnalyzer analyzer;
    strcpy(parser.text, "This is a test document. This document is used for testing tokenization and analysis.");
    tokenize(&parser);
    analyze_tokens(&analyzer, &parser);
    generate_report(&analyzer);
    for (int i = 0; i < analyzer.count; i++) {
        printf("%s %d\n", analyzer.tokens[i], analyzer.token_count[i]);
    }
}