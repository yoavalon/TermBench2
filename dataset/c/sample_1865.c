#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

int parse_and_tokenize(const char *text, char *tokens[]) {
    regex_t regex;
    regmatch_t matches[MAX_TOKENS];
    int num_tokens = 0;
    char *token;

    regcomp(&regex, "\\b\\w+\\b", REG_EXTENDED);
    if (regexec(&regex, text, MAX_TOKENS, matches, 0) == 0) {
        for (int i = 0; matches[i].rm_so != -1 && num_tokens < MAX_TOKENS; i++) {
            token = (char *)malloc(matches[i].rm_eo - matches[i].rm_so + 1);
            strncpy(token, text + matches[i].rm_so, matches[i].rm_eo - matches[i].rm_so);
            token[matches[i].rm_eo - matches[i].rm_so] = '\0';

            if (strpbrk(token, ".") != NULL) {
                char *end;
                strtod(token, &end);
                if (*end == '\0') {
                    free(token);
                    continue;
                }
            }

            tokens[num_tokens++] = token;
        }
    }
    regfree(&regex);
    return num_tokens;
}

int main() {
    const char *text = "The value of pi is approximately 3.14159. The number 2.718 is also significant.";
    char *tokens[MAX_TOKENS];
    int num_tokens = parse_and_tokenize(text, tokens);

    for (int i = 0; i < num_tokens; i++) {
        printf("%s ", tokens[i]);
        free(tokens[i]);
    }
    printf("\n");

    return 0;
}