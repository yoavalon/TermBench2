#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_LINE_LENGTH 1024

char** tokenize_text(const char* text) {
    char** tokens = (char**)malloc(MAX_TOKENS * sizeof(char*));
    int token_count = 0;
    char line[MAX_LINE_LENGTH];
    strcpy(line, text);
    char* token = strtok(line, " ");
    while (token != NULL && token_count < MAX_TOKENS) {
        tokens[token_count] = (char*)malloc(strlen(token) + 1);
        strcpy(tokens[token_count], token);
        token_count++;
        token = strtok(NULL, " ");
    }
    return tokens;
}

char** process_document(const char* doc) {
    char** tokens = (char**)malloc(MAX_TOKENS * sizeof(char*));
    int token_count = 0;
    char line[MAX_LINE_LENGTH];
    strcpy(line, doc);
    char* ptr = line;
    while (*ptr != '\0' && token_count < MAX_TOKENS) {
        while (isspace(*ptr)) ptr++;
        if (*ptr == '\0') break;
        char* start = ptr;
        while (!isspace(*ptr) && *ptr != '\0') ptr++;
        size_t len = ptr - start;
        tokens[token_count] = (char*)malloc(len + 1);
        strncpy(tokens[token_count], start, len);
        tokens[token_count][len] = '\0';
        token_count++;
    }
    return tokens;
}

void main() {
    const char* document = "This is a sample document for parsing. It contains multiple lines and words.";
    char** result = process_document(document);
    for (int i = 0; i < MAX_TOKENS && result[i] != NULL; i++) {
        printf("%s ", result[i]);
        free(result[i]);
    }
    free(result);
    printf("\n");
}