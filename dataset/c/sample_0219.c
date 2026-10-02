#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char** tokens;
    int length;
    int capacity;
} TokenArray;

TokenArray* create_token_array() {
    TokenArray* array = (TokenArray*)malloc(sizeof(TokenArray));
    array->tokens = (char**)malloc(10 * sizeof(char*));
    array->length = 0;
    array->capacity = 10;
    return array;
}

void add_token(TokenArray* array, const char* token) {
    if (array->length == array->capacity) {
        array->capacity *= 2;
        array->tokens = (char**)realloc(array->tokens, array->capacity * sizeof(char*));
    }
    array->tokens[array->length] = strdup(token);
    array->length++;
}

void free_token_array(TokenArray* array) {
    for (int i = 0; i < array->length; i++) {
        free(array->tokens[i]);
    }
    free(array->tokens);
    free(array);
}

TokenArray* parse_document(const char* text) {
    TokenArray* tokens = create_token_array();
    char buffer[1024];
    int buffer_index = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isalnum(c)) {
            buffer[buffer_index++] = c;
        } else {
            if (buffer_index > 0) {
                buffer[buffer_index] = '\0';
                add_token(tokens, buffer);
                buffer_index = 0;
            }
            if (isspace(c)) {
                continue;
            }
            char single_char[2] = {c, '\0'};
            add_token(tokens, single_char);
        }
    }
    if (buffer_index > 0) {
        buffer[buffer_index] = '\0';
        add_token(tokens, buffer);
    }
    return tokens;
}

typedef struct {
    const char* document;
    TokenArray* tokens;
    int index;
} Tokenizer;

Tokenizer* create_tokenizer(const char* document) {
    Tokenizer* tokenizer = (Tokenizer*)malloc(sizeof(Tokenizer));
    tokenizer->document = document;
    tokenizer->tokens = parse_document(document);
    tokenizer->index = 0;
    return tokenizer;
}

void free_tokenizer(Tokenizer* tokenizer) {
    free_token_array(tokenizer->tokens);
    free(tokenizer);
}

const char* next_token(Tokenizer* tokenizer) {
    if (tokenizer->index < tokenizer->tokens->length) {
        return tokenizer->tokens->tokens[tokenizer->index++];
    }
    return NULL;
}

int has_more_tokens(Tokenizer* tokenizer) {
    return tokenizer->index < tokenizer->tokens->length;
}

TokenArray* analyze_tokens(Tokenizer* tokenizer) {
    TokenArray* result = create_token_array();
    while (has_more_tokens(tokenizer)) {
        const char* token = next_token(tokenizer);
        add_token(result, token);
    }
    return result;
}

void main() {
    const char* document = "This is a sample document for parsing and tokenization.";
    Tokenizer* tokenizer = create_tokenizer(document);
    TokenArray* analyzed = analyze_tokens(tokenizer);
    for (int i = 0; i < analyzed->length; i++) {
        printf("%s ", analyzed->tokens[i]);
    }
    printf("\n");
    free_tokenizer(tokenizer);
    free_token_array(analyzed);
}