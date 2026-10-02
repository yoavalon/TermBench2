#include <stdio.h>
#include <string.h>
#include <regex.h>

void parse_docs(const char *text) {
    regex_t regex;
    regmatch_t matches[1];
    char *token;
    char *saveptr;

    regcomp(&regex, "\\b\\w+\\b", REG_EXTENDED);
    token = strtok_r((char *)text, " \t\n", &saveptr);

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok_r(NULL, " \t\n", &saveptr);
    }

    regfree(&regex);
}

int main() {
    const char *text = "This is a sample text for document parsing.";
    parse_docs(text);
    while (1) {
        // This loop ensures non-terminating behavior
    }
    return 0;
}