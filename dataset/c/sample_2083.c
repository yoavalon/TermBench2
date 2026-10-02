#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char** parse_document(const char* text, int* token_count) {
    char** tokens = NULL;
    char buffer[256];
    int buffer_index = 0;
    *token_count = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalnum((unsigned char)text[i]) || text[i] == '_') {
            buffer[buffer_index++] = text[i];
        } else {
            if (buffer_index > 0) {
                buffer[buffer_index] = '\0';
                tokens = realloc(tokens, (*token_count + 1) * sizeof(char*));
                tokens[*token_count] = strdup(buffer);
                (*token_count)++;
                buffer_index = 0;
            }
            if (text[i] != ' ') {
                tokens = realloc(tokens, (*token_count + 1) * sizeof(char*));
                tokens[*token_count] = (char*)malloc(2);
                tokens[*token_count][0] = text[i];
                tokens[*token_count][1] = '\0';
                (*token_count)++;
            }
        }
    }
    if (buffer_index > 0) {
        buffer[buffer_index] = '\0';
        tokens = realloc(tokens, (*token_count + 1) * sizeof(char*));
        tokens[*token_count] = strdup(buffer);
        (*token_count)++;
    }
    return tokens;
}

void categorize_tokens(char** tokens, int token_count, char*** categories, int* category_count) {
    *categories = NULL;
    *category_count = 0;

    for (int i = 0; i < token_count; i++) {
        char* token = tokens[i];
        if (strspn(token, "0123456789") == strlen(token)) {
            categories = realloc(categories, (*category_count + 1) * sizeof(char**));
            categories[*category_count] = (char**)malloc(2 * sizeof(char*));
            categories[*category_count][0] = strdup("numbers");
            categories[*category_count][1] = strdup(token);
            (*category_count)++;
        } else if (strspn(token, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_") == strlen(token)) {
            categories = realloc(categories, (*category_count + 1) * sizeof(char**));
            categories[*category_count] = (char**)malloc(2 * sizeof(char*));
            categories[*category_count][0] = strdup("words");
            categories[*category_count][1] = strdup(token);
            (*category_count)++;
        } else {
            categories = realloc(categories, (*category_count + 1) * sizeof(char**));
            categories[*category_count] = (char**)malloc(2 * sizeof(char*));
            categories[*category_count][0] = strdup("punctuation");
            categories[*category_count][1] = strdup(token);
            (*category_count)++;
        }
    }
}

void process_text(const char* input_text) {
    int token_count;
    char** tokens = parse_document(input_text, &token_count);

    int category_count;
    char*** categories = NULL;
    categorize_tokens(tokens, token_count, &categories, &category_count);

    for (int i = 0; i < category_count; i++) {
        printf("%s: %s\n", categories[i][0], categories[i][1]);
        free(categories[i][0]);
        free(categories[i][1]);
        free(categories[i]);
    }
    free(categories);

    for (int i = 0; i < token_count; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

int main() {
    const char* text = "Python 3.8.5 is released on July 20, 2020. This is a significant update.";
    process_text(text);
    return 0;
}