#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TOKENS 100
#define MAX_WORD_LENGTH 100

char** process_document(const char* text, int max_tokens) {
    char* lower_text = (char*)malloc(strlen(text) + 1);
    char** tokens = (char**)malloc(max_tokens * sizeof(char*));
    for (int i = 0; i < max_tokens; i++) {
        tokens[i] = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
    }

    for (int i = 0; text[i]; i++) {
        lower_text[i] = tolower(text[i]);
    }
    lower_text[strlen(text)] = '\0';

    int token_count = 0;
    const char* start = lower_text;
    const char* end = lower_text;
    while (*end) {
        while (*end && !isspace(*end)) {
            end++;
        }
        if (end - start < MAX_WORD_LENGTH) {
            strncpy(tokens[token_count], start, end - start);
            tokens[token_count][end - start] = '\0';
            token_count++;
        }
        if (token_count >= max_tokens) {
            break;
        }
        start = end + 1;
        end = start;
    }

    free(lower_text);
    return tokens;
}

void main() {
    const char* doc = "This is a sample document for parsing and tokenization.";
    char** result = process_document(doc, MAX_TOKENS);

    for (int i = 0; i < MAX_TOKENS && result[i][0] != '\0'; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);

    return;
}