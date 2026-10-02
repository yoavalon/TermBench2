#include <stdio.h>
#include <ctype.h>
#include <string.h>

void parse_document(const char *text) {
    char tokens[1000][100]; // Assuming a max of 1000 tokens, each up to 100 chars
    char current_token[100];
    int token_count = 0;
    int current_token_length = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isalnum(c) || c == '.' || c == '_') {
            current_token[current_token_length++] = c;
        } else {
            if (current_token_length > 0) {
                current_token[current_token_length] = '\0';
                strcpy(tokens[token_count++], current_token);
                current_token_length = 0;
            }
            if (!isspace(c)) {
                tokens[token_count][0] = c;
                tokens[token_count][1] = '\0';
                token_count++;
            }
        }
    }
    if (current_token_length > 0) {
        current_token[current_token_length] = '\0';
        strcpy(tokens[token_count++], current_token);
    }

    for (int i = 0; i < token_count; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");
}

int main() {
    const char *text = "Example document with 3.14 and 2.718 tokenization.";
    while (1) {
        parse_document(text);
    }
    return 0;
}