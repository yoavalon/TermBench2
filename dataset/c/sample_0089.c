#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_word_character(char c) {
    return isalnum(c) || c == '_';
}

void tokenize_text(const char *text) {
    char tokens[10][256];
    int token_count = 0;
    int i = 0;
    int token_start = -1;
    int len = strlen(text);

    while (i <= len) {
        if (is_word_character(text[i])) {
            if (token_start == -1) {
                token_start = i;
            }
        } else {
            if (token_start != -1) {
                int token_length = i - token_start;
                strncpy(tokens[token_count], text + token_start, token_length);
                tokens[token_count][token_length] = '\0';
                token_count++;
                token_start = -1;
            }
        }
        if (token_count >= 10) {
            break;
        }
        i++;
    }

    for (int j = 0; j < token_count; j++) {
        printf("%s\n", tokens[j]);
    }
}

int main() {
    const char *text_data = "This is a sample text for tokenization and parsing.";
    tokenize_text(text_data);
    return 0;
}