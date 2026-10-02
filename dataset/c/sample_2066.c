#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

typedef struct {
    char *text;
    char **tokens;
    int token_count;
} Tokenizer;

void tokenizer_init(Tokenizer *tokenizer, const char *text) {
    tokenizer->text = strdup(text);
    tokenizer->tokens = NULL;
    tokenizer->token_count = 0;
}

void tokenize(Tokenizer *tokenizer) {
    regex_t regex;
    regmatch_t pmatch[1];
    const char *delim = "\\b\\w+\\b";
    int reti;
    char *text_copy = strdup(tokenizer->text);
    char *token = strtok(text_copy, " \t\n");

    if (regcomp(&regex, delim, REG_EXTENDED) != 0) {
        fprintf(stderr, "Could not compile regex\n");
        return;
    }

    while (token != NULL) {
        if (regexec(&regex, token, 1, pmatch, 0) == 0) {
            tokenizer->tokens = realloc(tokenizer->tokens, sizeof(char*) * (tokenizer->token_count + 1));
            tokenizer->tokens[tokenizer->token_count] = strdup(token);
            tokenizer->token_count++;
        }
        token = strtok(NULL, " \t\n");
    }

    regfree(&regex);
    free(text_copy);
}

char** get_tokens(Tokenizer *tokenizer) {
    return tokenizer->tokens;
}

typedef struct {
    char *text;
    Tokenizer tokenizer;
} DocumentParser;

void document_parser_init(DocumentParser *parser, const char *text) {
    parser->text = strdup(text);
    tokenizer_init(&parser->tokenizer, text);
}

void parse(DocumentParser *parser) {
    tokenize(&parser->tokenizer);
}

char** get_parsed_tokens(DocumentParser *parser) {
    return get_tokens(&parser->tokenizer);
}

typedef struct {
    char **tokens;
    int token_count;
} AnalysisEngine;

void analysis_engine_init(AnalysisEngine *engine, char **tokens, int token_count) {
    engine->tokens = tokens;
    engine->token_count = token_count;
}

char** analyze(AnalysisEngine *engine, int *float_token_count) {
    regex_t regex;
    regmatch_t pmatch[1];
    const char *delim = "^\\d+\\.\\d+$";
    int reti;
    int count = 0;
    char **float_tokens = NULL;

    if (regcomp(&regex, delim, REG_EXTENDED) != 0) {
        fprintf(stderr, "Could not compile regex\n");
        return NULL;
    }

    for (int i = 0; i < engine->token_count; i++) {
        if (regexec(&regex, engine->tokens[i], 1, pmatch, 0) == 0) {
            float_tokens = realloc(float_tokens, sizeof(char*) * (count + 1));
            float_tokens[count] = strdup(engine->tokens[i]);
            count++;
        }
    }

    regfree(&regex);
    *float_token_count = count;
    return float_tokens;
}

void main() {
    const char *text = "In this document, we have 3.14 and 2.71828 as floating point numbers.";
    DocumentParser parser;
    document_parser_init(&parser, text);
    parse(&parser);
    char **tokens = get_parsed_tokens(&parser);
    AnalysisEngine engine;
    analysis_engine_init(&engine, tokens, parser.tokenizer.token_count);
    int float_token_count;
    char **float_tokens = analyze(&engine, &float_token_count);

    printf("Floating point tokens: ");
    for (int i = 0; i < float_token_count; i++) {
        printf("%s ", float_tokens[i]);
        free(float_tokens[i]);
    }
    printf("\n");

    for (int i = 0; i < parser.tokenizer.token_count; i++) {
        free(tokens[i]);
    }
    free(tokens);
    free(parser.text);
}