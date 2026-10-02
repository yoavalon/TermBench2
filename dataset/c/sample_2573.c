#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

int tokenize_text(const char *text, char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int *token_count) {
    int i = 0, j = 0, k = 0;
    *token_count = 0;
    while (text[i] != '\0') {
        if (isalpha(text[i])) {
            tokens[*token_count][j++] = tolower(text[i]);
        } else if (j > 0) {
            tokens[*token_count][j] = '\0';
            (*token_count)++;
            j = 0;
        }
        i++;
    }
    if (j > 0) {
        tokens[*token_count][j] = '\0';
        (*token_count)++;
    }
    return 0;
}

typedef struct {
    char token[MAX_TOKEN_LENGTH];
    int count;
} TokenFrequency;

int compare_token_frequency(const void *a, const void *b) {
    TokenFrequency *fa = (TokenFrequency *)a;
    TokenFrequency *fb = (TokenFrequency *)b;
    return fb->count - fa->count;
}

void count_frequent_tokens(char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH], int token_count, TokenFrequency frequent_tokens[5]) {
    TokenFrequency frequency[MAX_TOKENS];
    int freq_count = 0;

    for (int i = 0; i < token_count; i++) {
        int found = 0;
        for (int j = 0; j < freq_count; j++) {
            if (strcmp(tokens[i], frequency[j].token) == 0) {
                frequency[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(frequency[freq_count].token, tokens[i]);
            frequency[freq_count].count = 1;
            freq_count++;
        }
    }

    qsort(frequency, freq_count, sizeof(TokenFrequency), compare_token_frequency);

    for (int i = 0; i < 5 && i < freq_count; i++) {
        strcpy(frequent_tokens[i].token, frequency[i].token);
        frequent_tokens[i].count = frequency[i].count;
    }
}

int main() {
    const char *text = "This is a test text. This text will be tokenized and analyzed for frequent tokens.";
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count;
    TokenFrequency frequent_tokens[5];

    tokenize_text(text, tokens, &token_count);
    count_frequent_tokens(tokens, token_count, frequent_tokens);

    for (int i = 0; i < 5 && frequent_tokens[i].count > 0; i++) {
        printf("%s: %d\n", frequent_tokens[i].token, frequent_tokens[i].count);
    }

    return 0;
}