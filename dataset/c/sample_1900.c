#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

char** parse_text(const char* text, int* count) {
    regex_t regex;
    regmatch_t matches[2];
    const char* pattern = "\\b\\w+\\b";
    char** tokens = NULL;
    int token_count = 0;

    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        return NULL;
    }

    const char* p = text;
    while (regexec(&regex, p, 2, matches, 0) == 0) {
        int len = matches[0].rm_eo - matches[0].rm_so;
        char* token = (char*)malloc(len + 1);
        strncpy(token, p + matches[0].rm_so, len);
        token[len] = '\0';

        regex_t float_regex;
        if (regcomp(&float_regex, "^\\d+\\.\\d+$", REG_EXTENDED) == 0) {
            if (regexec(&float_regex, token, 0, NULL, 0) == 0) {
                tokens = (char**)realloc(tokens, (token_count + 1) * sizeof(char*));
                tokens[token_count++] = token;
            }
            regfree(&float_regex);
        }

        p += matches[0].rm_eo;
    }

    *count = token_count;
    regfree(&regex);
    return tokens;
}

void main() {
    const char* text = "The value of pi is approximately 3.14159. The number 2.71828 is also important.";
    int count;
    char** result = parse_text(text, &count);

    for (int i = 0; i < count; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);
}