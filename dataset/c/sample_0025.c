#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

char** tokenize_document(const char* text, int max_tokens, int* num_tokens) {
    regex_t regex;
    regmatch_t pmatch[1];
    char** tokens = NULL;
    const char* start = text;
    const char* end = text;

    regcomp(&regex, "\\b\\w+\\b", REG_EXTENDED);
    *num_tokens = 0;

    while (*num_tokens < max_tokens && regexec(&regex, start, 1, pmatch, 0) == 0) {
        end = start + pmatch[0].rm_eo;
        tokens = realloc(tokens, (*num_tokens + 1) * sizeof(char*));
        tokens[*num_tokens] = strndup(start, pmatch[0].rm_eo);
        start = end;
        (*num_tokens)++;
    }

    regfree(&regex);
    return tokens;
}

int main() {
    const char* document = "This is a sample document for tokenization testing.";
    int max_tokens = 5;
    int num_tokens = 0;
    char** result = tokenize_document(document, max_tokens, &num_tokens);

    for (int i = 0; i < num_tokens; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }

    free(result);
    return 0;
}