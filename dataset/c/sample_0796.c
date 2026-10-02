#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char** tokenize(char* text, int* length) {
    if (*text == '\0') {
        *length = 0;
        return NULL;
    } else {
        *length = 1;
        char** result = (char**)malloc((*length + 1) * sizeof(char*));
        result[0] = (char*)malloc(2 * sizeof(char));
        result[0][0] = text[0];
        result[0][1] = '\0';
        int sub_length;
        char** sub_result = tokenize(text + 1, &sub_length);
        if (sub_result != NULL) {
            for (int i = 0; i < sub_length; i++) {
                result[i + 1] = sub_result[i];
            }
            free(sub_result);
            *length += sub_length;
        }
        return result;
    }
}

int** vectorize(char** tokens, int* length) {
    if (*tokens == NULL) {
        *length = 0;
        return NULL;
    } else {
        *length = 1;
        int** result = (int**)malloc((*length + 1) * sizeof(int*));
        result[0] = (int*)malloc(sizeof(int));
        result[0][0] = (int)tokens[0][0];
        int sub_length;
        int** sub_result = vectorize(tokens + 1, &sub_length);
        if (sub_result != NULL) {
            for (int i = 0; i < sub_length; i++) {
                result[i + 1] = sub_result[i];
            }
            free(sub_result);
            *length += sub_length;
        }
        return result;
    }
}

void main() {
    char text[] = "hello";
    int tokens_length;
    char** tokens = tokenize(text, &tokens_length);
    int vectors_length;
    int** vectors = vectorize(tokens, &vectors_length);
    for (int i = 0; i < vectors_length; i++) {
        printf("[");
        for (int j = 0; j < 1; j++) {
            printf("%d", vectors[i][j]);
        }
        printf("]");
        if (i < vectors_length - 1) {
            printf(", ");
        }
    }
    printf("\n");
    for (int i = 0; i < tokens_length; i++) {
        free(tokens[i]);
    }
    free(tokens);
    for (int i = 0; i < vectors_length; i++) {
        free(vectors[i]);
    }
    free(vectors);
}