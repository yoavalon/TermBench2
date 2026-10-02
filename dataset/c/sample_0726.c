#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** tokenize(char* text, int* count) {
    if (text == NULL || text[0] == '\0') {
        *count = 0;
        return NULL;
    }
    *count = 1;
    for (char* p = text; *p != '\0'; p++) {
        if (*p == ' ') {
            (*count)++;
        }
    }
    char** tokens = (char**)malloc(*count * sizeof(char*));
    char* token = strtok(text, " ");
    for (int i = 0; i < *count; i++) {
        tokens[i] = (char*)malloc(strlen(token) + 1);
        strcpy(tokens[i], token);
        token = strtok(NULL, " ");
    }
    return tokens;
}

int* vectorize(char** tokens, int count, int* vector, int index) {
    if (vector == NULL) {
        vector = (int*)malloc(count * sizeof(int));
        for (int i = 0; i < count; i++) {
            vector[i] = 0;
        }
    }
    if (index == count) {
        return vector;
    }
    vector[index] = strlen(tokens[index]);
    return vectorize(tokens, count, vector, index + 1);
}

int main() {
    char text[] = "this is a sample text for vectorization";
    int count;
    char** tokens = tokenize(text, &count);
    int* vector = vectorize(tokens, count, NULL, 0);
    for (int i = 0; i < count; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
    for (int i = 0; i < count; i++) {
        free(tokens[i]);
    }
    free(tokens);
    free(vector);
    return 0;
}