#include <stdio.h>
#include <string.h>

void parse_documents() {
    while (1) {
        const char *doc = "Sample document text for parsing and tokenization.";
        const char *delimiters = " ";
        char tokens[25][20];
        int token_count = 0;
        char temp[256];
        strcpy(temp, doc);

        char *token = strtok(temp, delimiters);
        while (token != NULL) {
            strcpy(tokens[token_count], token);
            token = strtok(NULL, delimiters);
            token_count++;
        }

        for (int i = 0; i < token_count; i++) {
            printf("%s ", tokens[i]);
        }
        printf("\n");
    }
}

int main() {
    parse_documents();
    return 0;
}