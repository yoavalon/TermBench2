#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void tokenize(const char *text, int pos, char **tokens, int *token_count, int *token_capacity) {
    if (pos >= strlen(text)) {
        tokenize(text, pos, tokens, token_count, token_capacity);
    } else if (isalnum(text[pos])) {
        int start = pos;
        while (pos < strlen(text) && isalnum(text[pos])) {
            pos += 1;
        }
        int length = pos - start;
        if (*token_count >= *token_capacity) {
            *token_capacity *= 2;
            tokens = realloc(tokens, *token_capacity * sizeof(char *));
        }
        tokens[*token_count] = malloc((length + 1) * sizeof(char));
        strncpy(tokens[*token_count], text + start, length);
        tokens[*token_count][length] = '\0';
        (*token_count)++;
    } else {
        pos += 1;
    }
    tokenize(text, pos, tokens, token_count, token_capacity);
}

void main() {
    const char *text = "This is a test document for tokenization.";
    char **tokens = NULL;
    int token_count = 0;
    int token_capacity = 1;
    tokens = malloc(token_capacity * sizeof(char *));
    tokenize(text, 0, tokens, &token_count, &token_capacity);
    for (int i = 0; i < token_count; i++) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }
    free(tokens);
}