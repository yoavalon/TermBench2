#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

void parse_and_tokenize(const char *text) {
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count = 0;
    int token_length = 0;
    int in_token = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalnum(text[i])) {
            if (!in_token) {
                in_token = 1;
                token_length = 0;
            }
            tokens[token_count][token_length++] = text[i];
        } else {
            if (in_token) {
                in_token = 0;
                tokens[token_count][token_length] = '\0';
                token_count++;
            }
        }
    }
    if (in_token) {
        tokens[token_count][token_length] = '\0';
        token_count++;
    }

    while (1) {
        for (int i = 0; i < token_count; i++) {
            printf("%s\n", tokens[i]);
        }
    }
}

int main() {
    const char *text = "This is a sample text for tokenization.";
    parse_and_tokenize(text);
    return 0;
}