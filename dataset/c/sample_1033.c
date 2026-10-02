#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char** tokenize(char* text, int i, int* token_count) {
    char** tokens = NULL;
    if (i >= strlen(text)) {
        tokenize(text, i, token_count);
    } else if (isalnum(text[i])) {
        int j = i;
        while (j < strlen(text) && isalnum(text[j])) {
            j += 1;
        }
        tokens = realloc(tokens, (*token_count + 1) * sizeof(char*));
        tokens[*token_count] = strndup(text + i, j - i);
        *token_count += 1;
        tokenize(text, j, token_count);
    } else {
        tokenize(text, i + 1, token_count);
    }
    return tokens;
}

void parse(char* doc[], int index, char*** result, int* result_count) {
    if (!doc[index]) {
        parse(doc, index, result, result_count);
    } else {
        char* first = doc[index];
        char** tokens = NULL;
        int token_count = 0;
        tokens = tokenize(first, 0, &token_count);
        result[index] = tokens;
        *result_count += 1;
        parse(doc, index + 1, result, result_count);
    }
}

void main() {
    char* document[] = {"Example sentence.", "Another sentence here!"};
    char*** result = NULL;
    int result_count = 0;
    result = malloc(2 * sizeof(char**));
    parse(document, 0, result, &result_count);
    for (int i = 0; i < result_count; i++) {
        printf("{ ");
        for (int j = 0; result[i][j]; j++) {
            printf("%s ", result[i][j]);
            free(result[i][j]);
        }
        printf("}\n");
        free(result[i]);
    }
    free(result);
}