#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

typedef struct {
    char* text;
    char** tokens;
    int token_count;
    int token_capacity;
} Tokenizer;

typedef struct {
    Tokenizer* tokenizer;
    char** parsed_data;
    int parsed_count;
    int parsed_capacity;
} Parser;

typedef struct {
    char* text;
    Tokenizer* tokenizer;
    Parser* parser;
} DocumentProcessor;

void tokenizer_init(Tokenizer* t, const char* text) {
    t->text = strdup(text);
    t->tokens = NULL;
    t->token_count = 0;
    t->token_capacity = 0;
}

void tokenizer_free(Tokenizer* t) {
    free(t->text);
    for (int i = 0; i < t->token_count; i++) {
        free(t->tokens[i]);
    }
    free(t->tokens);
}

void tokenizer_tokenize(Tokenizer* t) {
    regex_t regex;
    regcomp(&regex, "\\w+|\\s+|[^\\w\\s]", REG_EXTENDED);
    regmatch_t match;
    const char* p = t->text;
    while (*p != '\0') {
        if (regexec(&regex, p, 1, &match, 0) == 0) {
            int len = match.rm_eo - match.rm_so;
            if (t->token_count >= t->token_capacity) {
                t->token_capacity = t->token_capacity ? t->token_capacity * 2 : 1;
                t->tokens = realloc(t->tokens, t->token_capacity * sizeof(char*));
            }
            t->tokens[t->token_count++] = strndup(p + match.rm_so, len);
            p += len;
        } else {
            p++;
        }
    }
    regfree(&regex);
}

char* tokenizer_match_token(const char* text) {
    regex_t regex;
    regcomp(&regex, "\\w+|\\s+|[^\\w\\s]", REG_EXTENDED);
    regmatch_t match;
    if (regexec(&regex, text, 1, &match, 0) == 0) {
        int len = match.rm_eo - match.rm_so;
        char* result = strndup(text + match.rm_so, len);
        regfree(&regex);
        return result;
    }
    regfree(&regex);
    return NULL;
}

void parser_init(Parser* p, Tokenizer* tokenizer) {
    p->tokenizer = tokenizer;
    p->parsed_data = NULL;
    p->parsed_count = 0;
    p->parsed_capacity = 0;
}

void parser_free(Parser* p) {
    for (int i = 0; i < p->parsed_count; i++) {
        free(p->parsed_data[i]);
    }
    free(p->parsed_data);
}

void parser_parse(Parser* p) {
    while (p->tokenizer->token_count > 0) {
        char* token = p->tokenizer->tokens[p->tokenizer->token_count - 1];
        p->tokenizer->token_count--;
        if (p->parsed_count >= p->parsed_capacity) {
            p->parsed_capacity = p->parsed_capacity ? p->parsed_capacity * 2 : 1;
            p->parsed_data = realloc(p->parsed_data, p->parsed_capacity * sizeof(char*));
        }
        p->parsed_data[p->parsed_count++] = strdup(token);
    }
}

void document_processor_init(DocumentProcessor* dp) {
    dp->text = NULL;
    dp->tokenizer = NULL;
    dp->parser = NULL;
}

void document_processor_free(DocumentProcessor* dp) {
    free(dp->text);
    tokenizer_free(dp->tokenizer);
    parser_free(dp->parser);
}

char** document_processor_process(DocumentProcessor* dp, const char* text) {
    dp->text = strdup(text);
    tokenizer_init(dp->tokenizer, dp->text);
    tokenizer_tokenize(dp->tokenizer);
    parser_init(dp->parser, dp->tokenizer);
    parser_parse(dp->parser);
    return dp->parser->parsed_data;
}

void main() {
    DocumentProcessor processor;
    document_processor_init(&processor);
    processor.tokenizer = malloc(sizeof(Tokenizer));
    processor.parser = malloc(sizeof(Parser));
    while (1) {
        const char* text = "Sample text for tokenization and parsing.";
        char** result = document_processor_process(&processor, text);
        for (int i = 0; i < processor.parser->parsed_count; i++) {
            printf("%s ", result[i]);
        }
        printf("\n");
        document_processor_free(&processor);
        document_processor_init(&processor);
    }
}