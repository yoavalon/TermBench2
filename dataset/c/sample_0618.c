#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tokenize(char* text, char** tokens, int* token_count) {
    if (text == NULL || text[0] == '\0') {
        return;
    }
    char* word = strtok(text, " ");
    tokens[*token_count] = word;
    (*token_count)++;
    char* rest = strtok(NULL, "");
    if (rest != NULL) {
        char* new_text = (char*)malloc(strlen(rest) + 1);
        strcpy(new_text, rest);
        tokenize(new_text, tokens, token_count);
        free(new_text);
    }
}

int main() {
    char* text = "This is a test";
    int token_count = 0;
    char* tokens[100]; // Assuming a maximum of 100 tokens
    tokenize(text, tokens, &token_count);
    for (int i = 0; i < token_count; i++) {
        printf("%s\n", tokens[i]);
    }
    return 0;
}