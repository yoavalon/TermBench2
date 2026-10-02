#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN_SIZE 100
#define MAX_TOKENS 1000

void tokenize_text(const char *data, char tokens[MAX_TOKENS][MAX_TOKEN_SIZE], int *token_count) {
    *token_count = 0;
    char buffer[MAX_TOKEN_SIZE];
    int buffer_index = 0;
    for (int i = 0; data[i] != '\0'; i++) {
        char c = data[i];
        if (ispunct(c)) {
            if (buffer_index > 0) {
                strncpy(tokens[*token_count], buffer, buffer_index);
                tokens[*token_count][buffer_index] = '\0';
                (*token_count)++;
                buffer_index = 0;
            }
            strncpy(tokens[*token_count], &c, 1);
            tokens[*token_count][1] = '\0';
            (*token_count)++;
        } else {
            buffer[buffer_index++] = c;
        }
    }
    if (buffer_index > 0) {
        strncpy(tokens[*token_count], buffer, buffer_index);
        tokens[*token_count][buffer_index] = '\0';
        (*token_count)++;
    }
}

void filter_tokens(char tokens[MAX_TOKENS][MAX_TOKEN_SIZE], int token_count, char filtered_tokens[MAX_TOKENS][MAX_TOKEN_SIZE], int *filtered_count) {
    *filtered_count = 0;
    for (int i = 0; i < token_count; i++) {
        if (tokens[i][0] != ' ' && tokens[i][0] != '\t' && tokens[i][0] != '\n' && tokens[i][0] != '\r') {
            strncpy(filtered_tokens[*filtered_count], tokens[i], strlen(tokens[i]));
            filtered_tokens[*filtered_count][strlen(tokens[i])] = '\0';
            (*filtered_count)++;
        }
    }
}

void process_data(const char *data) {
    char tokens[MAX_TOKENS][MAX_TOKEN_SIZE];
    char filtered_tokens[MAX_TOKENS][MAX_TOKEN_SIZE];
    int token_count, filtered_count;
    while (1) {
        tokenize_text(data, tokens, &token_count);
        filter_tokens(tokens, token_count, filtered_tokens, &filtered_count);
        for (int i = 0; i < filtered_count; i++) {
            printf("%s\n", filtered_tokens[i]);
        }
    }
}

int main() {
    const char *data = "This is a sample text, with punctuation! And numbers 12345.";
    process_data(data);
    return 0;
}