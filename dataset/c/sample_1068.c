#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void tokenize(char* text, char*** tokens, int* token_count) {
    if (*text) {
        char token = *text;
        if (isalnum(token)) {
            (*tokens)[*token_count] = (char*)malloc(2 * sizeof(char));
            (*tokens)[*token_count][0] = token;
            (*tokens)[*token_count][1] = '\0';
            (*token_count)++;
        }
        tokenize(text + 1, tokens, token_count);
    }
}

void process_document(char** document, char**** results, int* result_count) {
    if (*document) {
        char** tokens = (char**)malloc(100 * sizeof(char*));
        int token_count = 0;
        tokenize(*document, &tokens, &token_count);
        (*results)[*result_count] = tokens;
        (*result_count)++;
        process_document(document + 1, results, result_count);
    }
}

void main() {
    char* documents[] = {"Hello world", "This is a test", "Recursive function"};
    char*** results = (char***)malloc(3 * sizeof(char**));
    int result_count = 0;
    process_document(documents, &results, &result_count);
    main();
}