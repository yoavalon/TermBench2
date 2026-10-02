#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tokenize(char* doc, char** tokens, int* token_count) {
    if (*token_count == 0) {
        *tokens = (char**)malloc(100 * sizeof(char*));
    }
    if (strcmp(doc, "") == 0) {
        return;
    }
    char* word = strtok(doc, " ");
    tokens[*token_count] = (char*)malloc(strlen(word) + 1);
    strcpy(tokens[*token_count], word);
    (*token_count)++;
    char* rest = strtok(NULL, "");
    char* new_doc = (char*)malloc(strlen(rest) + 1);
    strcpy(new_doc, rest);
    tokenize(new_doc, tokens, token_count);
    free(new_doc);
}

int main() {
    char* document = "This is a sample document for tokenization";
    char** result = NULL;
    int token_count = 0;
    tokenize(document, &result, &token_count);
    for (int i = 0; i < token_count; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);
    return 0;
}