#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

int* process_sequence(const char* text) {
    static int sequence[10];
    int index = 0;
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count = 0;
    int i = 0, j = 0;

    while (text[i] != '\0') {
        if (isspace(text[i])) {
            if (j > 0) {
                tokens[token_count][j] = '\0';
                token_count++;
                j = 0;
            }
        } else {
            tokens[token_count][j] = text[i];
            j++;
        }
        i++;
    }
    if (j > 0) {
        tokens[token_count][j] = '\0';
        token_count++;
    }

    for (i = 0; i < token_count && index < 10; i++) {
        if (isdigit(tokens[i][0])) {
            sequence[index] = atoi(tokens[i]);
            index++;
        }
    }

    return sequence;
}

int main() {
    const char* data = "The sequence starts with 1, 2, 3, and continues with 4, 5, 6, 7, 8, 9, 10.";
    int* result = process_sequence(data);
    for (int i = 0; i < 10 && result[i] != '\0'; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}