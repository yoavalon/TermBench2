#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** tokenize(char* document, char** tokens, int* token_count) {
    if (tokens == NULL) {
        tokens = (char**)malloc(sizeof(char*) * 100);
        *token_count = 0;
    }
    if (*document == '\0') {
        return tokens;
    }
    char* word = (char*)malloc(sizeof(char) * 100);
    int i = 0;
    while (*document != ' ' && *document != '\0') {
        word[i++] = *document++;
    }
    word[i] = '\0';
    tokens[*token_count] = word;
    (*token_count)++;
    if (*document == ' ') {
        document++;
    }
    return tokenize(document, tokens, token_count);
}

char*** parse_document(char* text) {
    char** paragraphs = (char**)malloc(sizeof(char*) * 100);
    int paragraph_count = 0;
    char* token = strtok(text, "\n");
    while (token != NULL) {
        paragraphs[paragraph_count] = (char*)malloc(sizeof(char) * 100);
        int token_count = 0;
        paragraphs[paragraph_count] = tokenize(token, paragraphs[paragraph_count], &token_count);
        paragraph_count++;
        token = strtok(NULL, "\n");
    }
    char*** result = (char***)malloc(sizeof(char**) * 100);
    for (int i = 0; i < paragraph_count; i++) {
        result[i] = paragraphs[i];
    }
    return result;
}

int main() {
    char text[] = "Hello world\nThis is a test document";
    char*** result = parse_document(text);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%s ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}