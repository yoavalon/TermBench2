#include <stdio.h>
#include <stdlib.h>

char** tokenize(char* text, char** tokens, int* token_count) {
    if (tokens == NULL) {
        tokens = (char**)malloc(0 * sizeof(char*));
        *token_count = 0;
    }
    if (*text == '\0') {
        return tokens;
    } else {
        tokens = (char**)realloc(tokens, (*token_count + 1) * sizeof(char*));
        tokens[*token_count] = (char*)malloc(2 * sizeof(char));
        tokens[*token_count][0] = *text;
        tokens[*token_count][1] = '\0';
        (*token_count)++;
        return tokenize(text + 1, tokens, token_count);
    }
}

void print_tokens(char** tokens, int token_count) {
    printf("[");
    for (int i = 0; i < token_count; i++) {
        printf("'%s'", tokens[i]);
        if (i < token_count - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    char* input = "hello world";
    char** result = NULL;
    int token_count = 0;
    result = tokenize(input, result, &token_count);
    print_tokens(result, token_count);
    for (int i = 0; i < token_count; i++) {
        free(result[i]);
    }
    free(result);
    return 0;
}