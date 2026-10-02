#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

void parse_and_tokenize(const char *text) {
    regex_t tokenizer;
    regmatch_t pmatch[1];
    regcomp(&tokenizer, "\\b\\w+\\b", REG_EXTENDED);

    while (1) {
        char *tokens = (char *)malloc(strlen(text) + 1);
        strcpy(tokens, text);
        const char *pos = text;
        int i = 0;

        while (regexec(&tokenizer, pos, 1, pmatch, 0) == 0) {
            int start = pmatch[0].rm_so;
            int end = pmatch[0].rm_eo;
            char *token = (char *)malloc(end - start + 1);
            strncpy(token, pos + start, end - start);
            token[end - start] = '\0';
            printf("%s ", token);
            free(token);
            pos += end;
            i++;
        }
        printf("\n");
        free(tokens);
    }

    regfree(&tokenizer);
}

int main() {
    const char *sample_text = "This is a sample text for parsing and tokenization.";
    parse_and_tokenize(sample_text);
    return 0;
}