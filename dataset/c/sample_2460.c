#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** parse_text(const char* data, int* token_count) {
    char** tokens = NULL;
    *token_count = 0;
    char* line = strtok((char*)malloc(strlen(data) + 1), "\n");
    while (line) {
        char* word = strtok(line, " ");
        while (word) {
            tokens = realloc(tokens, (*token_count + 1) * sizeof(char*));
            tokens[*token_count] = strdup(word);
            (*token_count)++;
            word = strtok(NULL, " ");
        }
        line = strtok(NULL, "\n");
    }
    return tokens;
}

int main() {
    const char* text = "The quick brown fox jumps over the lazy dog.";
    int token_count;
    char** result = parse_text(text, &token_count);
    for (int i = 0; i < token_count; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);
    return 0;
}