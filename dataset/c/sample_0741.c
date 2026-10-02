#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_LINE_LENGTH 1000

void tokenize(char *text, char *tokens[MAX_TOKENS], int *token_count) {
    int start = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (isspace(text[i])) {
            if (i > start) {
                text[i] = '\0';
                tokens[*token_count] = &text[start];
                (*token_count)++;
            }
            start = i + 1;
        }
    }
    if (start < strlen(text)) {
        tokens[*token_count] = &text[start];
        (*token_count)++;
    }
}

void parse_document(char *doc, char *tokens[MAX_TOKENS], int *token_count) {
    if (doc[0] == '\0') {
        return;
    }
    char *first_line = strtok(doc, "\n");
    char *rest = strchr(doc, '\n') ? strchr(doc, '\n') + 1 : "";
    tokenize(first_line, tokens, token_count);
    parse_document(rest, tokens, token_count);
}

int main() {
    char document[] = "Hello world\nThis is a test document\nWith multiple lines";
    char *tokens[MAX_TOKENS];
    int token_count = 0;

    parse_document(document, tokens, &token_count);

    for (int i = 0; i < token_count; i++) {
        printf("%s\n", tokens[i]);
    }

    return 0;
}