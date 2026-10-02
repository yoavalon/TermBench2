#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

void parse_document(char *data, char **tokens, int *count) {
    regex_t regex;
    regmatch_t matches[11];
    int match_count = 0;

    regcomp(&regex, "\\b\\w+\\b", REG_EXTENDED);
    while (regexec(&regex, data, 11, matches, 0) == 0) {
        for (int i = 0; i < 10 && matches[i].rm_so != -1; i++) {
            tokens[i] = (char *)malloc(matches[i].rm_eo - matches[i].rm_so + 1);
            strncpy(tokens[i], data + matches[i].rm_so, matches[i].rm_eo - matches[i].rm_so);
            tokens[i][matches[i].rm_eo - matches[i].rm_so] = '\0';
            match_count++;
        }
        data += matches[0].rm_eo;
    }
    regfree(&regex);
    *count = match_count;
}

int main() {
    char *text = "This is a sample text document for parsing and tokenization.";
    char *tokens[10];
    int count;

    parse_document(text, tokens, &count);
    for (int i = 0; i < count; i++) {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }

    return 0;
}