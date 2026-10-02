#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

int tokenize_document(const char *doc, char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int *token_count) {
    int i = 0, j = 0, k = 0;
    *token_count = 0;
    while (doc[i] != '\0') {
        if (isalnum(doc[i]) || doc[i] == '.') {
            tokens[*token_count][k++] = doc[i];
        } else if (k > 0) {
            tokens[*token_count][k] = '\0';
            (*token_count)++;
            k = 0;
        }
        i++;
    }
    if (k > 0) {
        tokens[*token_count][k] = '\0';
        (*token_count)++;
    }
    return 0;
}

int analyze_token_precision(char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int token_count, int precision_values[MAX_TOKENS]) {
    int i = 0;
    for (i = 0; i < token_count; i++) {
        char *end;
        double float_value = strtod(tokens[i], &end);
        if (*end == '\0') {
            precision_values[i] = strcspn(tokens[i], ".") == strlen(tokens[i]) - 1 ? 0 : strlen(end + 1);
        } else {
            precision_values[i] = -1;
        }
    }
    return 0;
}

int main() {
    const char *document = "The value of pi is approximately 3.14159. The number e is roughly 2.71828.";
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count;
    int precision_values[MAX_TOKENS];

    tokenize_document(document, tokens, &token_count);
    analyze_token_precision(tokens, token_count, precision_values);

    for (int i = 0; i < token_count; i++) {
        if (precision_values[i] != -1) {
            printf("%d ", precision_values[i]);
        }
    }
    printf("\n");

    return 0;
}