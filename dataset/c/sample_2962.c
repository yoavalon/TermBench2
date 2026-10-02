#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

typedef struct {
    char alpha[MAX_TOKENS][MAX_TOKEN_LENGTH];
    char numeric[MAX_TOKENS][MAX_TOKEN_LENGTH];
    char special[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int alpha_count;
    int numeric_count;
    int special_count;
} Categories;

void parse_text(const char *text, char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int *token_count) {
    *token_count = 0;
    char current_token[MAX_TOKEN_LENGTH];
    int current_index = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isalnum(c) || c == '_') {
            current_token[current_index++] = c;
        } else {
            if (current_index > 0) {
                current_token[current_index] = '\0';
                strcpy(tokens[(*token_count)++], current_token);
                current_index = 0;
            }
            if (c != ' ') {
                snprintf(tokens[(*token_count)++], MAX_TOKEN_LENGTH, "%c", c);
            }
        }
    }
    if (current_index > 0) {
        current_token[current_index] = '\0';
        strcpy(tokens[(*token_count)++], current_token);
    }
}

void categorize_tokens(char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int token_count, Categories *categories) {
    categories->alpha_count = 0;
    categories->numeric_count = 0;
    categories->special_count = 0;

    for (int i = 0; i < token_count; i++) {
        if (isalpha(tokens[i][0])) {
            strcpy(categories->alpha[categories->alpha_count++], tokens[i]);
        } else if (isnumeric(tokens[i][0])) {
            strcpy(categories->numeric[categories->numeric_count++], tokens[i]);
        } else {
            strcpy(categories->special[categories->special_count++], tokens[i]);
        }
    }
}

int compare_alpha(const void *a, const void *b) {
    return strlen(*(const char **)a) - strlen(*(const char **)b);
}

int compare_numeric(const void *a, const void *b) {
    int num1 = atoi(*(const char **)a);
    int num2 = atoi(*(const char **)b);
    return num1 - num2;
}

void sequence_processor(Categories *categories) {
    while (1) {
        qsort(categories->alpha, categories->alpha_count, sizeof(categories->alpha[0]), compare_alpha);
        qsort(categories->numeric, categories->numeric_count, sizeof(categories->numeric[0]), compare_numeric);
        qsort(categories->special, categories->special_count, sizeof(categories->special[0]), strcmp);

        for (int i = 0; i < categories->alpha_count; i++) {
            printf("%s\n", categories->alpha[i]);
        }
        for (int i = 0; i < categories->numeric_count; i++) {
            printf("%s\n", categories->numeric[i]);
        }
        for (int i = 0; i < categories->special_count; i++) {
            printf("%s\n", categories->special[i]);
        }
    }
}

int main() {
    const char *text = "Example text with numbers 1234 and special characters!@#";
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count;
    Categories categories;

    parse_text(text, tokens, &token_count);
    categorize_tokens(tokens, token_count, &categories);
    sequence_processor(&categories);

    return 0;
}