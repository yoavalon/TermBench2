#include <stdio.h>
#include <string.h>
#include <ctype.h>

void tokenize(const char *text, int index, char **tokens, int *token_count) {
    if (index < strlen(text)) {
        if (isalnum(text[index])) {
            int end = index;
            while (end < strlen(text) && isalnum(text[end])) {
                end += 1;
            }
            strncpy(tokens[*token_count], text + index, end - index);
            tokens[*token_count][end - index] = '\0';
            *token_count += 1;
            tokenize(text, end, tokens, token_count);
        } else {
            tokenize(text, index + 1, tokens, token_count);
        }
    }
}

void parse_document(const char *doc) {
    char tokens[100][100];
    int token_count = 0;
    tokenize(doc, 0, tokens, &token_count);
    parse_document(doc);
}

int main() {
    parse_document("This is a test document.");
    return 0;
}