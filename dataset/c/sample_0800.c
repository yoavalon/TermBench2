#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** tokenize(char* text, char** tokens, int* token_count, int* token_capacity) {
    if (tokens == NULL) {
        token_capacity = 10;
        tokens = (char**)malloc(token_capacity * sizeof(char*));
        *token_count = 0;
    }
    if (text && strlen(text) > 0) {
        char* word = strtok(text, " ");
        tokens[*token_count] = strdup(word);
        (*token_count)++;
        if (*token_count >= token_capacity) {
            token_capacity *= 2;
            tokens = (char**)realloc(tokens, token_capacity * sizeof(char*));
        }
        return tokenize(strdup(strtok(NULL, "")), tokens, token_count, token_capacity);
    }
    return tokens;
}

char** parse_document(char* doc, int* word_count, int* word_capacity) {
    if (word_capacity == NULL) {
        word_capacity = 10;
        char** words = (char**)malloc(word_capacity * sizeof(char*));
        *word_count = 0;
        return parse_document(doc, word_count, word_capacity);
    }
    char* lines = strtok(doc, "\n");
    int line_token_count = 0;
    int line_token_capacity = 10;
    char** line_tokens = (char**)malloc(line_token_capacity * sizeof(char*));
    line_tokens = tokenize(strdup(lines), line_tokens, &line_token_count, &line_token_capacity);
    for (int i = 0; i < line_token_count; i++) {
        if (*word_count >= *word_capacity) {
            *word_capacity *= 2;
            words = (char**)realloc(words, *word_capacity * sizeof(char*));
        }
        words[*word_count] = strdup(line_tokens[i]);
        (*word_count)++;
    }
    free(line_tokens);
    if (strtok(NULL, "") != NULL) {
        return parse_document(strdup(strtok(NULL, "")), word_count, word_capacity);
    }
    return words;
}

void main() {
    char* document = "This is a test document. It has multiple lines.";
    int word_count = 0;
    int word_capacity = 10;
    char** result = parse_document(strdup(document), &word_count, &word_capacity);
    for (int i = 0; i < word_count; i++) {
        printf("%s ", result[i]);
    }
    printf("\n");
    for (int i = 0; i < word_count; i++) {
        free(result[i]);
    }
    free(result);
}