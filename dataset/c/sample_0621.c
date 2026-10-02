#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* process_text(const char* text, int index, int* result, int* result_size) {
    if (index >= strlen(text)) {
        return result;
    } else {
        result[*result_size] = (int)text[index];
        (*result_size)++;
        return process_text(text, index + 1, result, result_size);
    }
}

void main() {
    const char* text = "Hello, World!";
    int result_size = 0;
    int* vector = (int*)malloc(strlen(text) * sizeof(int));
    vector = process_text(text, 0, vector, &result_size);

    for (int i = 0; i < result_size; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    free(vector);
}