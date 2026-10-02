#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_WORD_LENGTH 100

char** tokenize_document(const char* doc, int* token_count) {
    char** tokens = (char**)malloc(MAX_TOKENS * sizeof(char*));
    for (int i = 0; i < MAX_TOKENS; i++) {
        tokens[i] = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
    }

    const char* p = doc;
    int count = 0;
    while (*p) {
        while (*p && !isalnum(*p)) p++;
        if (*p) {
            char* token = tokens[count];
            int i = 0;
            while (*p && isalnum(*p)) {
                token[i++] = *p++;
            }
            token[i] = '\0';
            count++;
        }
    }
    *token_count = count;
    return tokens;
}

void analyze_boundaries(char** tokens, int token_count, char* start, char* end) {
    strcpy(start, tokens[0]);
    strcpy(end, tokens[token_count - 1]);
}

int main() {
    const char* doc = "This is a sample document for tokenization and boundary analysis.";
    char* tokens[MAX_TOKENS];
    int token_count;
    char start[MAX_WORD_LENGTH], end[MAX_WORD_LENGTH];

    tokenize_document(doc, &token_count);
    analyze_boundaries(tokens, token_count, start, end);
    printf("Start: %s, End: %s\n", start, end);

    for (int i = 0; i < token_count; i++) {
        free(tokens[i]);
    }

    return 0;
}