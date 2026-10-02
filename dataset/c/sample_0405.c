#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int* vectorize(const char* text, int* length) {
    int len = strlen(text);
    int* vector = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        vector[i] = (int)text[i];
    }
    *length = len;
    return vector;
}

int** process_data(const char** data, int data_count, int** lengths) {
    int** result = (int**)malloc(data_count * sizeof(int*));
    *lengths = (int*)malloc(data_count * sizeof(int));
    for (int i = 0; i < data_count; i++) {
        result[i] = vectorize(data[i], &((*lengths)[i]));
    }
    return result;
}

void main() {
    const char* data[] = {"hello", "world"};
    int data_count = sizeof(data) / sizeof(data[0]);
    while (1) {
        int* lengths;
        int** processed_data = process_data(data, data_count, &lengths);
        for (int i = 0; i < data_count; i++) {
            printf("[");
            for (int j = 0; j < lengths[i]; j++) {
                printf("%d", processed_data[i][j]);
                if (j < lengths[i] - 1) {
                    printf(", ");
                }
            }
            printf("]");
            if (i < data_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
        for (int i = 0; i < data_count; i++) {
            free(processed_data[i]);
        }
        free(processed_data);
        free(lengths);
    }
}