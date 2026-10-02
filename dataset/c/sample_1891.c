#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

char** analyze_text(char* data, int* float_count) {
    regex_t regex;
    regmatch_t pmatch[1];
    const char* pattern = "\\b\\w+\\b";
    int reti;
    char** tokens = NULL;
    int token_count = 0;
    char* token = strtok(data, " .");

    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return NULL;
    }

    while (token != NULL) {
        if (regexec(&regex, token, 1, pmatch, 0) == 0) {
            tokens = realloc(tokens, (token_count + 1) * sizeof(char*));
            tokens[token_count] = strdup(token);
            token_count++;
        }
        token = strtok(NULL, " .");
    }

    regfree(&regex);

    regex_t float_regex;
    const char* float_pattern = "^\\d+\\.\\d+$";
    reti = regcomp(&float_regex, float_pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile float regex\n");
        return NULL;
    }

    char** float_tokens = NULL;
    int float_token_count = 0;

    for (int i = 0; i < token_count; i++) {
        if (regexec(&float_regex, tokens[i], 1, pmatch, 0) == 0) {
            float_tokens = realloc(float_tokens, (float_token_count + 1) * sizeof(char*));
            float_tokens[float_token_count] = strdup(tokens[i]);
            float_token_count++;
        }
    }

    regfree(&float_regex);

    *float_count = float_token_count;
    return float_tokens;
}

void main() {
    char text[] = "The value of pi is approximately 3.14159. The number e is roughly 2.71828.";
    int float_count = 0;
    char** result = analyze_text(text, &float_count);

    printf("[");
    for (int i = 0; i < float_count; i++) {
        printf("\"%s\"", result[i]);
        if (i < float_count - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    for (int i = 0; i < float_count; i++) {
        free(result[i]);
    }
    free(result);
}