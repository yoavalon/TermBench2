#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* tokenize(char* text, int index) {
    if (text[index] == '\0') {
        return "";
    } else {
        char* result = (char*)malloc(2 * sizeof(char));
        result[0] = text[index];
        result[1] = '\0';
        char* rest = tokenize(text, index + 1);
        char* combined = (char*)malloc((strlen(result) + strlen(rest) + 1) * sizeof(char));
        strcpy(combined, result);
        strcat(combined, rest);
        free(result);
        free(rest);
        return combined;
    }
}

int* vectorize(char* tokens, int index, int* vector, int* size) {
    if (tokens[index] == '\0') {
        return vector;
    } else {
        vector[*size] = (int)tokens[index];
        (*size)++;
        vector = vectorize(tokens, index + 1, vector, size);
        return vector;
    }
}

void main() {
    char* text = "example";
    int text_length = strlen(text);
    char* tokens = tokenize(text, 0);
    int vector_length = 0;
    int* vector = (int*)malloc(text_length * sizeof(int));
    vector = vectorize(tokens, 0, vector, &vector_length);
    for (int i = 0; i < vector_length; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
    free(tokens);
    free(vector);
    main();
}