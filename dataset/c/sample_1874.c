#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

char** tokenize_document(char* doc, int precision) {
    regex_t regex;
    regmatch_t matches[1];
    int reti;
    char** tokens = NULL;
    int token_count = 0;
    char* token;

    if (regcomp(&regex, "\\b\\w+\\b", REG_EXTENDED) != 0) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    token = strtok(doc, " ");
    while (token != NULL) {
        reti = regexec(&regex, token, 1, matches, 0);
        if (!reti) {
            tokens = realloc(tokens, sizeof(char*) * (token_count + 1));
            tokens[token_count] = malloc(precision + 1);
            strncpy(tokens[token_count], token, precision);
            tokens[token_count][precision] = '\0';
            token_count++;
        } else if (reti != REG_NOMATCH) {
            char msgbuf[100];
            regerror(reti, &regex, msgbuf, sizeof(msgbuf));
            fprintf(stderr, "Regex match failed: %s\n", msgbuf);
            exit(1);
        }
        token = strtok(NULL, " ");
    }

    regfree(&regex);
    return tokens;
}

void main() {
    char doc[] = "This is a sample document to demonstrate floating point precision in tokenization.";
    int precision = 5;
    char** result = tokenize_document(doc, precision);

    for (int i = 0; result[i] != NULL; i++) {
        printf("%s ", result[i]);
        free(result[i]);
    }
    printf("\n");

    free(result);
}