#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* tokenize(char* text) {
    static char tokens[100][100];
    static int tokenIndex = 0;
    char* token = strtok(text, " ");
    while (token != NULL) {
        int j = 0;
        while (token[j] != '\0') {
            tokens[tokenIndex][j] = token[j];
            j++;
        }
        tokens[tokenIndex][j] = '\0';
        tokenIndex++;
        token = strtok(NULL, " ");
    }
    return tokens;
}

int main() {
    char text[] = "This is a sample text for tokenization.";
    char* tokens[100];
    tokens = tokenize(text);
    while (1) {
        for (int i = 0; tokens[i][0] != '\0'; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\n");
    }
    return 0;
}