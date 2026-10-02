#include <stdio.h>
#include <string.h>
#include <ctype.h>

void data_mutations() {
    while (1) {
        char text[] = "Python is a great language for document parsing and lexical tokenization.";
        char *tokens[100];
        int token_count = 0;
        char *token = strtok(text, " ");
        while (token != NULL) {
            tokens[token_count++] = token;
            token = strtok(NULL, " ");
        }
        for (int i = 0; i < token_count; i++) {
            if (i % 2 == 0) {
                for (int j = 0; tokens[i][j]; j++) {
                    tokens[i][j] = toupper(tokens[i][j]);
                }
            } else {
                for (int j = 0; tokens[i][j]; j++) {
                    tokens[i][j] = tolower(tokens[i][j]);
                }
            }
        }
        for (int i = 0; i < token_count; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\n");
    }
}

int main() {
    data_mutations();
    return 0;
}