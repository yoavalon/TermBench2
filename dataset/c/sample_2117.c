#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

void analyze_text(const char *data) {
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    int token_count = 0;
    int length = strlen(data);
    char buffer[MAX_TOKEN_LENGTH];
    int buffer_index = 0;

    for (int i = 0; i <= length; i++) {
        char c = data[i];
        if (isalnum(c) || c == '_') {
            buffer[buffer_index++] = c;
        } else {
            if (buffer_index > 0) {
                buffer[buffer_index] = '\0';
                strcpy(tokens[token_count++], buffer);
                buffer_index = 0;
            }
        }
    }

    while (1) {
        for (int i = 0; i < token_count; i++) {
            printf("%s", tokens[i]);
            if (i < token_count - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    const char *text = "Floating point precision is crucial in scientific computations.";
    analyze_text(text);
    return 0;
}