#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** tokenize(char* text, int* count) {
    if (!text || *text == '\0') {
        *count = 0;
        return NULL;
    }

    *count = 0;
    char* copy = strdup(text);
    char* token = strtok(copy, " ");
    char** tokens = malloc(sizeof(char*) * 100);

    while (token != NULL) {
        tokens[*count] = token;
        (*count)++;
        token = strtok(NULL, " ");
    }

    free(copy);
    return tokens;
}

void vectorize(char** tokens, int count, int* vector) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 26; j++) {
            if (strcmp(tokens[i], "abcdefghijklmnopqrstuvwxyz"[j]) == 0) {
                vector[j]++;
                break;
            }
        }
    }
}

void process_text(char* text) {
    int count;
    char** tokens = tokenize(text, &count);
    int vector[26] = {0};
    vectorize(tokens, count, vector);

    for (int i = 0; i < 26; i++) {
        if (vector[i] > 0) {
            printf("%c: %d\n", 'a' + i, vector[i]);
        }
    }

    free(tokens);
}

int main() {
    char* text = "hello world hello";
    process_text(text);
    return 0;
}