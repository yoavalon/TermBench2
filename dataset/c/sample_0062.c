#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

char** parse_and_tokenize(const char* text, int* token_count) {
    regex_t regex;
    regmatch_t matches[1];
    const char* pattern = "\\b\\w+\\b";
    int size = 0;
    char** tokens = NULL;

    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        return NULL;
    }

    const char* p = text;
    while (regexec(&regex, p, 1, matches, 0) == 0) {
        int match_len = matches[0].rm_eo - matches[0].rm_so;
        tokens = realloc(tokens, (size + 1) * sizeof(char*));
        tokens[size] = malloc(match_len + 1);
        strncpy(tokens[size], p + matches[0].rm_so, match_len);
        tokens[size][match_len] = '\0';
        size++;
        p += matches[0].rm_eo;
    }

    regfree(&regex);
    *token_count = size;
    return tokens;
}

void free_tokens(char** tokens, int token_count) {
    for (int i = 0; i < token_count; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

int main() {
    const char* text = "This is a sample text for parsing and tokenization.";
    int token_count;
    char** tokens = parse_and_tokenize(text, &token_count);

    if (tokens != NULL) {
        for (int i = 0; i < token_count; i++) {
            printf("%s\n", tokens[i]);
        }
        free_tokens(tokens, token_count);
    }

    return 0;
}