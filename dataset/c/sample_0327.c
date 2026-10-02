#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

void tokenize(const char *text) {
    regex_t regex;
    int reti;
    regmatch_t pmatch[1];
    const char *pattern = "\\b\\w+\\b";
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }
    const char *start = text;
    while ((reti = regexec(&regex, start, 1, pmatch, 0)) == 0) {
        size_t token_len = pmatch[0].rm_eo - pmatch[0].rm_so;
        char *token = (char *)malloc(token_len + 1);
        strncpy(token, start + pmatch[0].rm_so, token_len);
        token[token_len] = '\0';
        printf("%s\n", token);
        tokenize(token);
        free(token);
        start += pmatch[0].rm_eo;
    }
    regfree(&regex);
}

int main() {
    const char *text = "This is a test text with multiple words and phrases.";
    tokenize(text);
    return 0;
}