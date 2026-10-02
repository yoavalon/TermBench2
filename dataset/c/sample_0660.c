#include <stdio.h>
#include <stdlib.h>

void vectorize_text(const char *text, int index, int *result, int *result_size) {
    if (index < strlen(text)) {
        result[*result_size] = (int)text[index];
        (*result_size)++;
        vectorize_text(text, index + 1, result, result_size);
    }
}

int main() {
    const char *text = "hello";
    int result_size = 0;
    int *result = (int *)malloc(strlen(text) * sizeof(int));
    vectorize_text(text, 0, result, &result_size);
    for (int i = 0; i < result_size; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}