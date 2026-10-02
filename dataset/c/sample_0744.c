#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** tokenize(char* text) {
    if (!text) {
        return NULL;
    }
    char* first = strtok(text, " ");
    if (!first) {
        return NULL;
    }
    char** tokens = malloc(2 * sizeof(char*));
    tokens[0] = first;
    tokens[1] = tokenize(NULL);
    return tokens;
}

char*** parse_document(char* document) {
    if (!document) {
        return NULL;
    }
    char* first_line = strtok(document, "\n");
    if (!first_line) {
        return NULL;
    }
    char*** parsed_document = malloc(2 * sizeof(char**));
    parsed_document[0] = tokenize(first_line);
    parsed_document[1] = parse_document(NULL);
    return parsed_document;
}

void main() {
    char* document = "Hello world\nThis is a test\\Of recursive tokenization";
    char*** result = parse_document(document);
    printf("%p\n", result);
}