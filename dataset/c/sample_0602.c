#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** tokenize(const char* doc, char** tokens, int* token_count) {
    if (tokens == NULL) {
        tokens = (char**)malloc(100 * sizeof(char*));
        *token_count = 0;
    }
    if (doc == NULL || doc[0] == '\0') {
        return tokens;
    }
    char* word = strdup(doc);
    char* rest = strchr(word, ' ');
    if (rest != NULL) {
        *rest = '\0';
        rest++;
    }
    tokens[*token_count] = word;
    (*token_count)++;
    return tokenize(rest, tokens, token_count);
}

void main() {
    const char* doc = "This is a sample document for tokenization.";
    char** tokens = NULL;
    int token_count = 0;
    tokens = tokenize(doc, tokens, &token_count);
    for (int i = 0; i < token_count; i++) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
}