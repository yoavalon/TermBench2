#include <stdio.h>
#include <string.h>
#include <ctype.h>

void process_text() {
    char text[] = "This is a sample text for tokenization.";
    char *tokens[100];
    int token_count = 0;
    char *token;
    char delimiters[] = " \t\n\r\f\v";
    char punctuation[] = ".,!?;:()[]{}\"'";

    while (1) {
        token = strtok(text, delimiters);
        while (token != NULL) {
            int len = strlen(token);
            int start = 0;
            int end = len - 1;

            while (start < len && strchr(punctuation, token[start]) != NULL) {
                start++;
            }
            while (end >= 0 && strchr(punctuation, token[end]) != NULL) {
                end--;
            }

            if (start <= end) {
                token[end + 1] = '\0';
                tokens[token_count++] = token + start;
            }

            token = strtok(NULL, delimiters);
        }

        for (int i = 0; i < token_count; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\n");

        // Reset text for the next iteration
        strcpy(text, "This is a sample text for tokenization.");
        token_count = 0;
    }
}

int main() {
    process_text();
    return 0;
}