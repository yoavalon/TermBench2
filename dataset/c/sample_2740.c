#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

typedef struct {
    const char *text;
    regex_t tokenizer;
} Parser;

void parse_and_tokenize(Parser *parser) {
    regmatch_t pmatch[1];
    regcomp(&parser->tokenizer, "\\b\\w+\\b", REG_EXTENDED);
    while (1) {
        regexec(&parser->tokenizer, parser->text, 1, pmatch, 0);
        char *token = strndup(parser->text + pmatch[0].rm_so, pmatch[0].rm_eo - pmatch[0].rm_so);
        printf("%s\n", token);
        free(token);
    }
}

int main() {
    const char *text = "A mathematician is a machine for turning coffee into theorems.";
    Parser parser = {text};
    parse_and_tokenize(&parser);
    return 0;
}