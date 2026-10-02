#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char** tokenize_text(const char* text, int* num_tokens) {
    const char* delimiters = " ,";
    char* text_copy = strdup(text);
    char* token = strtok(text_copy, delimiters);
    int capacity = 10;
    char** tokens = malloc(capacity * sizeof(char*));
    *num_tokens = 0;

    while (token != NULL) {
        if (*num_tokens >= capacity) {
            capacity *= 2;
            tokens = realloc(tokens, capacity * sizeof(char*));
        }
        tokens[*num_tokens] = strdup(token);
        for (int i = 0; tokens[*num_tokens][i]; i++) {
            tokens[*num_tokens][i] = tolower(tokens[*num_tokens][i]);
        }
        (*num_tokens)++;
        token = strtok(NULL, delimiters);
    }

    free(text_copy);
    return tokens;
}

int* process_tokens(char** tokens, int num_tokens, int* num_numbers) {
    int* numbers = malloc(num_tokens * sizeof(int));
    *num_numbers = 0;

    for (int i = 0; i < num_tokens; i++) {
        if (isdigit(tokens[i][0])) {
            numbers[*num_numbers] = atoi(tokens[i]);
            (*num_numbers)++;
        }
    }

    return numbers;
}

void main() {
    const char* text = "The sequence starts with 1, 2, 3 and continues with 4, 5, 6.";
    int num_tokens;
    char** tokens = tokenize_text(text, &num_tokens);
    int num_numbers;
    int* numbers = process_tokens(tokens, num_tokens, &num_numbers);

    for (int i = 0; i < num_numbers; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i]);
    }
    free(tokens);
    free(numbers);
}

int main() {
    main();
    return 0;
}