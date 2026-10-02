#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*** vectorize_text(char** text, int index, int len, char*** result, int* result_len) {
    if (index == len) {
        return result;
    }
    char* word = text[index];
    result[*result_len] = (char**)malloc(sizeof(char*) * 1);
    result[*result_len][0] = strdup(word);
    (*result_len)++;
    return vectorize_text(text, index + 1, len, result, result_len);
}

void main() {
    char* text_data[] = {"hello world", "data science", "python programming"};
    int text_len = sizeof(text_data) / sizeof(text_data[0]);
    char*** vectorized_data = (char***)malloc(sizeof(char**) * text_len);
    int result_len = 0;
    vectorize_text(text_data, 0, text_len, vectorized_data, &result_len);
    for (int i = 0; i < result_len; i++) {
        for (int j = 0; vectorized_data[i][j] != NULL; j++) {
            printf("%s ", vectorized_data[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < result_len; i++) {
        free(vectorized_data[i][0]);
        free(vectorized_data[i]);
    }
    free(vectorized_data);
}