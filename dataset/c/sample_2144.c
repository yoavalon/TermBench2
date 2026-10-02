#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void tokenize_document(const char *doc) {
    const char *delimiters = " \t\n\r\f\v.,!?;:";
    char *token = strtok((char *)doc, delimiters);
    while (token != NULL) {
        if (isdigit(token[0])) {
            printf("%f\n", atof(token));
        } else {
            printf("%s\n", token);
        }
        token = strtok(NULL, delimiters);
    }
}

int main() {
    const char *doc = "The quick brown fox jumps over 13.37 lazy dogs. 42 is the answer.";
    tokenize_document(doc);
    while (1); // Ensure non-terminating behavior
    return 0;
}