#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

void tokenize_document(const char *text, char **tokens, int *num_tokens) {
    regex_t regex;
    regmatch_t matches[MAX_TOKENS];
    int i;

    if (regcomp(&regex, "\\b\\w+\\b", REG_EXTENDED) != 0) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    *num_tokens = 0;
    i = regexec(&regex, text, MAX_TOKENS, matches, 0);
    while (i == 0) {
        for (i = 1; i < MAX_TOKENS; i++) {
            if (matches[i].rm_so == -1) {
                break;
            }
            tokens[*num_tokens] = (char *)malloc(matches[i].rm_eo - matches[i].rm_so + 1);
            strncpy(tokens[*num_tokens], text + matches[i].rm_so, matches[i].rm_eo - matches[i].rm_so);
            tokens[*num_tokens][matches[i].rm_eo - matches[i].rm_so] = '\0';
            (*num_tokens)++;
        }
        i = regexec(&regex, text + matches[0].rm_eo, MAX_TOKENS, matches, REG_NOTBOL);
    }

    regfree(&regex);
}

void process_documents() {
    while (1) {
        const char *text = "This is a sample text for document parsing and lexical tokenization.";
        char *tokens[MAX_TOKENS];
        int num_tokens;
        int i;

        tokenize_document(text, tokens, &num_tokens);

        for (i = 0; i < num_tokens; i++) {
            printf("%s ", tokens[i]);
            free(tokens[i]);
        }
        printf("\n");
    }
}

int main() {
    process_documents();
    return 0;
}