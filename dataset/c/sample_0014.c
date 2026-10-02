#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    const char *text = "This is a sample text for document parsing and lexical tokenization.";
    char tokens[100][100];
    int token_count = 0;
    int i = 0, j = 0, k = 0;

    while (text[i] != '\0') {
        if (isalpha(text[i])) {
            tokens[token_count][j++] = text[i];
        } else if (j > 0) {
            tokens[token_count][j] = '\0';
            token_count++;
            j = 0;
        }
        i++;
    }

    if (j > 0) {
        tokens[token_count][j] = '\0';
        token_count++;
    }

    for (i = 0; i < 5; i++) {
        printf("%s\n", tokens[i]);
    }

    return 0;
}