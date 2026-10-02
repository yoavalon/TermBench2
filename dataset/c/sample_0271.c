#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

typedef struct {
    char* text;
    char** tokens;
    int token_count;
} DocumentParser;

typedef struct {
    char** tokens;
    int token_count;
    int* frequency;
} TokenAnalyzer;

void DocumentParser_init(DocumentParser* parser, const char* text) {
    parser->text = strdup(text);
    parser->tokens = NULL;
    parser->token_count = 0;
}

void preprocess_text(DocumentParser* parser) {
    for (int i = 0; parser->text[i]; i++) {
        parser->text[i] = tolower(parser->text[i]);
    }
    regex_t re;
    regcomp(&re, "\\s+", REG_EXTENDED);
    regmatch_t match;
    char* new_text = (char*)malloc(strlen(parser->text) + 1);
    int pos = 0;
    const char* src = parser->text;
    while (regexec(&re, src, 1, &match, 0) == 0) {
        strncpy(new_text + pos, src, match.rm_so);
        pos += match.rm_so;
        new_text[pos++] = ' ';
        src += match.rm_eo;
    }
    strcpy(new_text + pos, src);
    free(parser->text);
    parser->text = new_text;
    regfree(&re);
}

void tokenize(DocumentParser* parser) {
    regex_t re;
    regcomp(&re, "\\b\\w+\\b", REG_EXTENDED);
    regmatch_t match;
    const char* src = parser->text;
    int count = 0;
    while (regexec(&re, src, 1, &match, 0) == 0) {
        count++;
        src += match.rm_eo;
    }
    parser->tokens = (char**)malloc(count * sizeof(char*));
    parser->token_count = count;
    src = parser->text;
    count = 0;
    while (regexec(&re, src, 1, &match, 0) == 0) {
        parser->tokens[count] = (char*)malloc(match.rm_eo - match.rm_so + 1);
        strncpy(parser->tokens[count], src + match.rm_so, match.rm_eo - match.rm_so);
        parser->tokens[count][match.rm_eo - match.rm_so] = '\0';
        count++;
        src += match.rm_eo;
    }
    regfree(&re);
}

void TokenAnalyzer_init(TokenAnalyzer* analyzer, char** tokens, int token_count) {
    analyzer->tokens = tokens;
    analyzer->token_count = token_count;
    analyzer->frequency = (int*)calloc(token_count, sizeof(int));
}

void analyze_frequency(TokenAnalyzer* analyzer) {
    for (int i = 0; i < analyzer->token_count; i++) {
        for (int j = 0; j < analyzer->token_count; j++) {
            if (strcmp(analyzer->tokens[i], analyzer->tokens[j]) == 0) {
                analyzer->frequency[i]++;
            }
        }
    }
}

void main() {
    const char* text_data = "Example document text for parsing and tokenization. This is a simple example.";
    DocumentParser parser;
    DocumentParser_init(&parser, text_data);
    preprocess_text(&parser);
    tokenize(&parser);
    TokenAnalyzer analyzer;
    TokenAnalyzer_init(&analyzer, parser.tokens, parser.token_count);
    analyze_frequency(&analyzer);
    for (int i = 0; i < analyzer.token_count; i++) {
        printf("%s: %d\n", analyzer.tokens[i], analyzer.frequency[i]);
        free(analyzer.tokens[i]);
    }
    free(analyzer.tokens);
    free(analyzer.frequency);
    free(parser.text);
}

int main() {
    main();
    return 0;
}